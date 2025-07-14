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
        vector<vector<int>> result;
        for (short int i = 0; i < grid.size(); ++i) {
            result.push_back({});
            for (short int j = 0; j < grid[i].size(); ++j) {
                for (auto q : grid[(i - grid.size() / k) % grid.size()]) cout << q << " ";
                result[i].push_back(grid[(i - grid.size() / k) % grid.size()][(j - k) % grid[i].size()]);
            }
            cout << endl << (i - grid.size() / k) % grid.size() << endl;
        }
        return result;
    }
};
// @lc code=end

