# LeetCode Algorithmic Challenges Solutions

[![LeetCode](https://img.shields.io/badge/LeetCode-000000?style=for-the-badge&logo=LeetCode&logoColor=#d16c06)](https://leetcode.com/)
[![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)](https://python.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](https://opensource.org/licenses/MIT)

> Прокачиваем навыки программирования, развиваем алгоритмическое мышление, оптимизируем код, готовимся к техническим собеседованиям.

## Оглавление
- [Таблица решений](#-table-of-solutions)
- [Автоматическое обновление](#-автоматическое-обновление)
- [Требования](#-требования)
- [Структура репозитория](#-структура-репозитория)
- [Лицензия](#-лицензия)

## TABLE OF SOLUTIONS

| ID | TASK NAME | DIFFICULTY | STATUS | SOLUTION |
|----|-----------|------------|--------|----------|
| 1 | [Two Sum](https://leetcode.com/problems/two-sum/description/) | easy | ✅ RESOLVED | [cpp](easy/1.two-sum.cpp) |
| 9 | [Palindrome Number](https://leetcode.com/problems/palindrome-number/description/) | easy | ✅ RESOLVED | [cpp](easy/9.palindrome-number.cpp) |
| 104 | [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/description/) | easy | ✅ RESOLVED | [cpp](easy/104.maximum-depth-of-binary-tree.cpp) |
| 169 | [Majority Element](https://leetcode.com/problems/majority-element/description/) | easy | 🔒 IN PROGRESS | [cpp](easy/169.majority-element.cpp) |

<!-- Last updated: 10-07-2025 01:11:33 -->

## Автоматическое обновление
В репозитории реализована система автоматического обновления таблицы решений:
- Скрипт `update_readme.py` отслеживает изменения через Git
- Извлекает данные о задачах из локального кеша LeetCode
- Форматирует информацию в таблицу Markdown
- Сохраняет историю решений и обновляет статусы задач

**Как использовать:**
```bash
python update_readme.py
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
