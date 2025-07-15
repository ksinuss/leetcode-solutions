/*
 * @lc app=leetcode id=1260 lang=cpp
 *
 * [1260] Shift 2D Grid
 */

// @lc code=start
using namespace std;
#include <vector>
#include <iostream>

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> result(grid.size(), vector<int>(grid[0].size()));
        k %= (grid.size() * grid[0].size());
        int start = (grid.size() * grid[0].size() - k) % (grid.size() * grid[0].size());
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                result[i][j] = grid[(start % (grid.size() * grid[0].size())) / grid[0].size()][(start++ % (grid.size() * grid[0].size())) % grid[0].size()];
            }
        }
        return result;
    }
};
// @lc code=end
