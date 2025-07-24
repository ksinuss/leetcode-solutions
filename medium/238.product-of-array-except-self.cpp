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
        vector<int> result;
        result.push_back(1); // for 0-index of result vector
        for (int i = 1; i < nums.size(); ++i) {
            result.push_back(result[i - 1] * nums[i - 1]);
            if (nums[i] != 1) {
                for (int j = 0; j < i; ++j) {
                    if (result[j] != 0) result[j] *= nums[i];
                }
            }
        }
        return result;
    }
};
// @lc code=end
