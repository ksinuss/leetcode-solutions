# LeetCode Algorithmic Challenges Solutions

[![LeetCode](https://img.shields.io/badge/LeetCode-000000?style=for-the-badge&logo=LeetCode&logoColor=#d16c06)](https://leetcode.com/)
[![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)](https://python.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](https://opensource.org/licenses/MIT)

> Прокачиваем навыки программирования, развиваем алгоритмическое мышление, оптимизируем код, готовимся к техническим собеседованиям.

## Оглавление
- [Таблица решений](#table-of-solutions)
- [Автоматическое обновление](#автоматическое-обновление)
- [Требования](#требования)
- [Структура репозитория](#структура-репозитория)
- [Лицензия](#лицензия)

## TABLE OF SOLUTIONS

| ID | TASK NAME | DIFFICULTY | STATUS | SOLUTION |
|----|-----------|------------|--------|----------|
| 1 | [Two Sum](https://leetcode.com/problems/two-sum/description/) | easy | ✅ RESOLVED | [cpp](easy/1.two-sum.cpp) |
| 9 | [Palindrome Number](https://leetcode.com/problems/palindrome-number/description/) | easy | ✅ RESOLVED | [cpp](easy/9.palindrome-number.cpp) |
| 14 | [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/description/) | easy | ✅ RESOLVED | [cpp](easy/14.longest-common-prefix.cpp) |
| 26 | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/) | easy | ✅ RESOLVED | [cpp](easy/26.remove-duplicates-from-sorted-array.cpp) |
| 49 | [Group Anagrams](https://leetcode.com/problems/group-anagrams/description/) | medium | ✅ RESOLVED | [cpp](medium/49.group-anagrams.cpp) |
| 66 | [Plus One](https://leetcode.com/problems/plus-one/description/) | easy | ✅ RESOLVED | [cpp](easy/66.plus-one.cpp) |
| 104 | [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/description/) | easy | ✅ RESOLVED | [cpp](easy/104.maximum-depth-of-binary-tree.cpp) |
| 169 | [Majority Element](https://leetcode.com/problems/majority-element/description/) | easy | ✅ RESOLVED | [cpp](easy/169.majority-element.cpp) |
| 217 | [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/description/) | easy | ✅ RESOLVED | [cpp](easy/217.contains-duplicate.cpp) |
| 242 | [Valid Anagram](https://leetcode.com/problems/valid-anagram/description/) | easy | ✅ RESOLVED | [cpp](easy/242.valid-anagram.cpp) |
| 263 | [Ugly Number](https://leetcode.com/problems/ugly-number/description/) | easy | ✅ RESOLVED | [cpp](easy/263.ugly-number.cpp) |
| 347 | [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/description/) | medium | ✅ RESOLVED | [cpp](medium/347.top-k-frequent-elements.cpp) |
| 559 | [Maximum Depth of N-ary Tree](https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/) | easy | ✅ RESOLVED | [cpp](easy/559.maximum-depth-of-n-ary-tree.cpp) |
| 1260 | [Shift 2D Grid](https://leetcode.com/problems/shift-2d-grid/description/) | easy | ✅ RESOLVED | [cpp](easy/1260.shift-2-d-grid.cpp) |

<!-- Last updated: 24-07-2025 13:08:59 -->

## Автоматическое обновление
В репозитории реализована система автоматического обновления таблицы решений:
- Скрипт `update_readme.py` отслеживает изменения через Git
- Извлекает данные о задачах из локального кеша LeetCode
- Форматирует информацию в таблицу Markdown
- Сохраняет историю решений и обновляет статусы задач

**Ручное обновление:**
```bash
python update_readme.py
```

**Автоматическое обновление при каждом коммите:**

1. Создать файл pre-commit hook в папке `.git/hooks` репозитория:
```bash
cd .git/hooks

touch pre-commit # без расширения!
```

2. Добавить в файл следующий код:
```bash
#!/bin/sh

echo "Updating solutions table..."
python scripts/update_readme.py

if [ $? -ne 0 ]; then
  echo "Error: Failed to update solutions table"
  exit 1
fi

git add README.md
```

3. Сохранить файл и дать ему права на выполнение:
```bash
chmod +x pre-commit
```

## Требования
Для работы скрипта обновления:
- [Python 3.7+](https://www.python.org/downloads/)
- [LeetCode Extension for VS Code](https://marketplace.visualstudio.com/items?itemName=LeetCode.vscode-leetcode)
- [Git](https://git-scm.com/downloads)
- Учетная запись на [LeetCode](https://leetcode.com/)

## Структура репозитория
```
leetcode-solutions/
├── easy/                   # Решения легких задач
├── medium/                 # Решения задач средней сложности
├── hard/                   # Решения сложных задач
├── scripts/
│   ├── update_readme.py    # Скрипт автообновления README
├── README.md               # Этот файл
└── LICENSE                 # Лицензия MIT
```

## Лицензия
Этот проект распространяется под лицензией MIT. Подробнее см. в файле [LICENSE](LICENSE).
