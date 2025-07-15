/*
 * @lc app=leetcode id=1260 lang=cpp
 *
 * [1260] Shift 2D Grid
 */

// @lc code=start
using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        k %= (grid.size() * grid[0].size());
        vector<vector<int>> result(grid.size(), vector<int>(grid[0].size()));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                int new_pos = (i * grid[0].size() + j + grid.size() * grid[0].size() - k) % (grid.size() * grid[0].size());
                result[i][j] = grid[new_pos / grid[0].size()][new_pos % grid[0].size()];
            }
        }
        return result;
    }
};
// @lc code=end
