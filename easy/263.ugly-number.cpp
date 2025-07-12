/*
 * @lc app=leetcode id=263 lang=cpp
 *
 * [263] Ugly Number
 */

// @lc code=start
#include <initializer_list>

class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }
        if (n % 2 != 0 && n % 3 != 0 && n % 5 != 0) {
            return false;
        }
        for (const auto& factor : {2, 3, 5}) {
            while (n % factor == 0) {
                n /= factor;
            }
        }
        return n == 1;
    }
};
// @lc code=end
