/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
using namespace std;
#include <array>
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, size_t> stock;
        vector<vector<string>> result;
        for (string str : strs) {
            array<int, 26> freq_chars{0};
            for (char c : str) ++freq_chars[c - 'a'];
            string freq_str;
            for (int freq : freq_chars) freq_str += to_string(freq) + '#';
            if (stock.find(freq_str) != stock.end()) result[stock[freq_str]].push_back(str);
            else {
                result.push_back({str});
                stock[freq_str] = result.size() - 1;
            }
        }
        return result;
    }
};
// @lc code=end
