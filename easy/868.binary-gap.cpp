/*
 * @lc app=leetcode id=868 lang=cpp
 *
 * [868] Binary Gap
 */

// @lc code=start
class Solution {
public:
    int binaryGap(int n) {
        int max_dist = 0;
        int count_zero = 0;
        while (n > 0) {
            if (n % 2 == 1) {
                if (count_zero > 0) {
                    if (count_zero > max_dist) {
                        max_dist = count_zero;
                    }
                    count_zero = 0;
                    continue;
                }
                ++count_zero;
            }
            else if (count_zero > 0) {
                ++count_zero;
            }
            n /= 2;
        }
        return max_dist;
    }
};
// @lc code=end
