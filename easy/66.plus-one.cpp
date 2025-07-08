/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool add = 1;
        for (auto i = digits.end() - 1; i != digits.begin() - 1; --i) {
            if (add) {
                if (i == digits.begin() && *i == 9) {
                    *i = 0;
                    digits.insert(digits.begin(), 1);
                    return digits;
                }
                *i = (*i + 1) % 10;
                add = !(*i > 0);
            } 
        }
        return digits;
    }
};
// @lc code=end
