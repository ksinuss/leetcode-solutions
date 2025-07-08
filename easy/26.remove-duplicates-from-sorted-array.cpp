/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        short unsigned int left = 0;
        for (short unsigned int right = 1; right < nums.size(); ++right) {
            if (nums[right] > nums[left]) {
                nums[++left] = nums[right];
            }
        }
        return left + 1;
    }
};
// @lc code=end
