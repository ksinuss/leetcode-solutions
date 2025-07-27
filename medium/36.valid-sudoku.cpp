/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<short int, short int> boxes_flags;
        unordered_map<short int, short int> columns_flags;
        for (short int row = 0; row < 9; ++row) {
            short int row_flag(0);
            for (short int column = 0; column < 9; ++column) {
                if (board[row][column] == '.') continue;
                int cell = board[row][column] - '0'; // to int (not ascii code)
                if (
                    row_flag & (1 << (cell - 1)) ||
                    columns_flags[column] & (1 << (cell - 1)) ||
                    boxes_flags[row / 3 * 3 + column / 3] & (1 << (cell - 1))
                ) {
                    return false;
                }
                row_flag |= (1 << (cell - 1));
                columns_flags[column] |= (1 << (cell - 1));
                boxes_flags[row / 3 * 3 + column / 3] |= (1 << (cell - 1));
            }
        }
        return true;
    }
};
// @lc code=end
