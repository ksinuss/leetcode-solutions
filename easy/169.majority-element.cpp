/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
using namespace std;
#include <vector>
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int suppose_num = nums[0];
        unsigned int current_count = 1; // for counting suppose_num
        for (unsigned int i = 1; i < nums.size(); ++i) {
            if (current_count == 0) {
                suppose_num = nums[i];
                ++current_count;
            }
            else if (nums[i] != suppose_num) {
                --current_count;
            }
            else {
                ++current_count;
            }
        }
        return suppose_num;
    }
};
// @lc code=end
