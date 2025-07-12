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

    # Return the path to LeetCode cache of tasks
    @staticmethod
    def get_cache_path() -> str:
        home_dir = os.path.expanduser('~')
        return os.path.join(home_dir, '.lc', 'leetcode', 'cache', 'problems.json')

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

    # Generating formatted row from raw solution info
    @staticmethod
    def generate_table_row(solution: dict) -> str:
        status = "🔒 IN PROGRESS"
        if solution.get('status') == 'ac':
            status = "✅ RESOLVED"
        title = f"[{solution.get('name')}]({solution.get('link')})"
        paths_solution = ', '.join(f"[{ext}]({solution.get('filepath')}.{ext})" for ext in solution.get('extension'))
        return f"| {solution['id']} | {title} | {solution.get('difficulty')} | {status} | {paths_solution} |\n"
    
    # Combining existing table rows with new solutions, sorting by task id
    def merge_and_sort_table_rows(self, old_rows: list[str], new_solutions: list[dict]) -> list[str]:
        merged_rows = {}
        for row in old_rows:
            try:
                task_id = int(row.split('|', 2)[1].strip())
                extensions = []
                for extension in row.rsplit('|', 2)[1].strip().split(', '):
                    # old_row format extension: "[{extension}](filepath.{extension})"
                    extensions.append(extension.rsplit('.', 1)[1][:-1])
                merged_rows[task_id] = [row, extensions]
            
            except (ValueError, IndexError):
                print(f"Error parsing row of table: {row}")
                continue
        for new_solution in new_solutions:
            if new_solution['id'] in merged_rows:
                new_extension = new_solution['extension']
                old_extensions = merged_rows[new_solution['id']][1]
                if new_extension in old_extensions:
                    new_solution['extension'] = old_extensions
                else:
                    new_solution['extension'] = sorted([new_extension] + old_extensions)
            merged_rows[new_solution['id']] = new_solution
        sum_rows = []
        for task_id in sorted(merged_rows):
            if type(merged_rows[task_id]) == dict:
                sum_rows.append(self.generate_table_row(merged_rows[task_id]))
            else:
                sum_rows.append(merged_rows[task_id][0])
        return sum_rows
    
    # Loading task data from LeetCode cache
    @staticmethod
    def load_task_data(cache_path: str, id: int) -> dict:
        try:
            if not os.path.exists(cache_path):
                raise FileNotFoundError(f"Cache file not found: {cache_path}")
            
            with open(cache_path, 'r', encoding='utf-8') as f:
                cache_content = json.load(f)
            return cache_content[len(cache_content) - id]
        
        except Exception as e:
            raise RuntimeError(f"Error loading tasks data: {str(e)}")
        
    # Getting necessary info about task for the progress table
    def parse_task_info(self, modified_file: str) -> dict:
        try:
            filepath_without_extension, solution_extension = modified_file.rsplit('.', 1)
            difficulty, file_name = filepath_without_extension.split('/', 1)
            task_data = self.load_task_data(self.cache_path, int(file_name.split('.', 1)[0]))
            return {
                'id': task_data.get('id'),
                'name': task_data.get('name'),
                'link': task_data.get('link'),
                'difficulty': difficulty,
                'status': task_data.get('state'),
                'extension': solution_extension,
                'filepath': filepath_without_extension
            }

        except Exception as e:
            raise RuntimeError(f"Error parsing modified file ({modified_file}): {str(e)}")

    # Getting beginning and end of table borders
    @staticmethod
    def get_table_borders(readme_path: str) -> tuple[int, int]:
        try:
            with open(readme_path, 'r', encoding='utf-8') as f:
                readme_content = f.readlines()
            start_table, end_table = -1, -1
            for i, line in enumerate(readme_content):
                if line.startswith("| ID | TASK NAME |"): # table header
                    start_table = i + 2
                elif start_table != -1 and line.startswith("<!--"): # comment on latest update
                    end_table = i - 1
                    break
            if start_table == -1: # if table not found: create a new
                readme_content.append(f"\n\n## TABLE OF SOLUTIONS\n\n")
                readme_content.append("| ID | TASK NAME | DIFFICULTY | STATUS | SOLUTION |\n")
                readme_content.append("|----|-----------|------------|--------|----------|\n")
                start_table = len(readme_content)
                end_table = len(readme_content)
                with open(readme_path, 'w', encoding='utf-8') as f:
                    f.writelines(readme_content)
            return (start_table, end_table)

        except Exception as e:
            raise RuntimeError(f"Error getting info about table: {str(e)}")

    # Writing updated table to readme with timestamp
    def update_progress_table(self, modified_files: list[str]) -> bool:
        try:
            start_table, end_table = self.get_table_borders(self.readme_path)
            with open(self.readme_path, 'r', encoding='utf-8') as f:
                readme_content = f.readlines()
            old_table = readme_content[start_table:end_table]
            new_solutions = [self.parse_task_info(modified_file) for modified_file in modified_files]
            updated_readme_content = (
                readme_content[:start_table] + 
                self.merge_and_sort_table_rows(old_table, new_solutions) +
                [f"\n<!-- Last updated: {datetime.now().strftime("%d-%m-%Y %H:%M:%S")} -->\n"] +
                readme_content[end_table + 2:]
            )
            with open(self.readme_path, 'w', encoding='utf-8') as f:
                f.writelines(updated_readme_content)
            return True

        except Exception as e:
            raise RuntimeError(f"Error updating table: {str(e)}")

# Starting work
if __name__ == "__main__":
    try:
        updater = ReadmeUpdater()
        modified_files = updater.get_modified_files()

        if not modified_files:
            print("No changes detected.")
            exit(0)
        
        updater.update_progress_table(modified_files)
    
    except Exception as e:
        raise RuntimeError(f"Error: {str(e)}")
