/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }
        string result = strs[0];
        for (short unsigned int i = 0; i < strs.size() - 1; ++i) {
            result = string(result.begin(), mismatch(result.begin(), result.end(), strs[i + 1].begin(), strs[i + 1].end()).first);
        }
        return result;
    }
};
// @lc code=end
