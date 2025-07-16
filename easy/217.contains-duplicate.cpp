/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> stock;
        for (int i = 0; i < nums.size(); ++i) {
            if (stock.find(nums[i]) != stock.end()) {
                return true;
            }
            stock[nums[i]] = i;
        }
        return false;
    }
};
// @lc code=end
