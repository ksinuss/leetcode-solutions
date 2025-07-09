/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
using namespace std;
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, short unsigned int> stock;
        for (short unsigned int index = 0; index < nums.size(); ++index) {
            int delta = target - nums[index];
            auto index_find = stock.find(delta);
            if (index_find != stock.end()) {
                return {index, index_find->second};
            }
            stock[nums[index]] = index;
        }
        return {};
    }
};
// @lc code=end
