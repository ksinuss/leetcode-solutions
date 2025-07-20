/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
using namespace std;
#include <array>
#include <string>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        array<int, 26> freqs;
        for (unsigned short int i = 0; i < s.size(); ++i) {
            ++freqs[s[i] - 'a'];
            --freqs[t[i] - 'a'];
        }
        for (int freq : freqs) {
            if (freq != 0) return false;
        }
        return true;
    }
};
// @lc code=end

