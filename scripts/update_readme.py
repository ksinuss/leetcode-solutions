# Libraries
import os
import json
import subprocess
from pathlib import Path
from datetime import datetime

class ReadmeUpdater:
    # Initializes configuration
    def __init__(self):
        self.repo_root = Path(__file__).parent.parent
        self.readme_path = os.path.join(self.repo_root, "README.md")
        self.cache_path = self.get_cache_path()
        self.solution_dirs = ["easy", "medium", "hard"]
        self.solutions = []
        self.tasks_data = {}

    # Return the path to LeetCode cache of tasks
    @staticmethod
    def get_cache_path() -> str:
        home_dir = os.path.expanduser('~')
        return os.path.join(home_dir, '.lc', 'leetcode', 'cache', 'problems.json')
    
    # Loading task data from LeetCode cache
    def load_tasks_data(self):
        try:
            if not os.path.exists(self.cache_path):
                raise FileNotFoundError(f"Cache file not found: {self.cache_path}")
            
            with open(self.cache_path, 'r', encoding='utf-8') as f:
                data = json.load(f)
                for problem in data:
                    self.tasks_data[problem['id']] = problem
        
        except Exception as e:
            raise RuntimeError(f"Error loading tasks data: {str(e)}")

    # Getting changed and new files with Git
    def get_modified_files(self) -> list[str]:
        try:
            git_result = subprocess.run(
                ['git', 'status', '--porcelain', '--untracked-files=all'],
                capture_output=True,
                text=True,
                cwd=self.repo_root
            )

            if git_result.returncode != 0:
                raise RuntimeError(f"Error Git command: {git_result.stderr}")
            
            modified_files = []
            for file in git_result.stdout.splitlines():
                status, filepath = file.strip().split()
                # If (Modified, Added, Untracked/new) and in (Easy, Medium, Hard)
                if status in ('M', 'A', '??') and any(filepath.startswith(dir) for dir in self.solution_dirs):
                    modified_files.append(filepath)
            return modified_files
        
        except Exception as e:
            raise RuntimeError(f"Error getting modified files: {str(e)}")
        
    # Getting necessary info about tasks for the progress table
    def parse_tasks_info(self, modified_files: list[str]) -> list[dict]:
        new_solutions = []
        for file in modified_files:
            try:
                difficulty, file_name = file.split('/')
                task_id, solution_extension = int(file_name.split('.')[0]), file_name.split('.')[2]
                new_solutions.append({
                    'id': task_id,
                    'name': self.tasks_data[task_id].get('name'),
                    'link': self.tasks_data[task_id].get('link'),
                    'difficulty': difficulty,
                    'status': self.tasks_data[task_id].get('state'),
                    'extension': solution_extension,
                    'filepath': file
                })

            except Exception as e:
                raise RuntimeError(f"Error parsing modified file ({file}): {str(e)}")
        return new_solutions

    # Generating formatted row from raw solution info
    @staticmethod
    def generate_table_row(solution: dict) -> str:
        status = "🔒 IN PROGRESS"
        if solution.get('status') == 'ac':
            status = "✅ RESOLVED"
        title = f"[{solution.get('name')}]({solution.get('link')})"
        return f"| {solution['id']} | {title} | {solution.get('difficulty')} | {status} | [{solution.get('extension')}]({solution.get('filepath')}) |\n"
    
    # Combining existing table rows with new solutions, sorting by task id
    @staticmethod
    def merge_and_sort_table_rows(old_rows: list[str], new_solutions: list[str]) -> list[str]:
        merged_rows = {}
        for row in old_rows:
            task_id = int(row.split('|', 2)[1].strip())
            merged_rows[task_id] = row
        for new_solution in new_solutions:
            task_id = int(new_solution.split('|', 2)[1].strip())
            merged_rows[task_id] = new_solution
        return [merged_rows[task_id] for task_id in sorted(merged_rows)]

    # Writing updated table to readme with timestamp
    def update_progress_table(self, modified_files) -> bool:
        try:
            with open(self.readme_path, 'r', encoding='utf-8') as f:
                readme_content = f.readlines()
            start_table, end_table = -1, -1
            for i, line in enumerate(readme_content):
                if line.startswith("| ID | TASK NAME |"):
                    start_table = i + 2
                elif start_table != -1 and line.startswith("<!--"):
                    end_table = i - 1
                    break
            if start_table == -1:
                readme_content.append(f"\n\n## TABLE OF SOLUTIONS\n\n")
                readme_content.append("| ID | TASK NAME | DIFFICULTY | STATUS | SOLUTION |\n")
                readme_content.append("|----|-----------|------------|--------|----------|\n")
                start_table = len(readme_content)
                end_table = len(readme_content)
            old_table = readme_content[start_table:end_table]
            new_solutions = []
            for task in self.parse_tasks_info(modified_files):
                new_solutions.append(self.generate_table_row(task))
            updated_readme_content = readme_content[:start_table]
            updated_readme_content += self.merge_and_sort_table_rows(old_table, new_solutions)
            updated_readme_content.append(f"\n<!-- Last updated: {datetime.now().strftime("%d-%m-%Y %H:%M:%S")} -->\n")
            updated_readme_content += readme_content[end_table + 2:]
            with open(self.readme_path, 'w', encoding='utf-8') as f:
                f.writelines(updated_readme_content)
            return True

        except Exception as e:
            raise RuntimeError(f"Error updating table: {str(e)}")

if __name__ == "__main__":
    try:
        updater = ReadmeUpdater()
        updater.load_tasks_data()
        modified_files = updater.get_modified_files()

        if not modified_files:
            raise RuntimeError("Modified files not found.")
        
        updater.update_progress_table(modified_files)
    
    except Exception as e:
        raise RuntimeError(f"Error: {str(e)}")
