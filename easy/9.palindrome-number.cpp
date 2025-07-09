/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
#include <math.h>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x / 10 == 0) {
            return true;
        }
        if (x % 10 == 0) {
            return false;
        }
        int len_x = log10(x);
        for (int i = 0; i < (len_x + 1) / 2; ++i) {
            if ((int)(x / pow(10, len_x - 2 * i)) % 10 != x % 10) {
                return false;
            }
            x /= 10;
        }
        return true;
    }
};
// @lc code=end
