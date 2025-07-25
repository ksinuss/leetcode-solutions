/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        bool all_ones = true;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != 1) all_ones = false;
            result[i] *= result[i - 1] * nums[i - 1];
        }
        if (all_ones) return result;
        int suffix = 1;
        for (int i = nums.size() - 1; i > -1; --i) {
            result[i] *= suffix;
            suffix *= nums[i];
        }
        return result;
    }
};
// @lc code=end
