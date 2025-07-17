/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
using namespace std;
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int, size_t> stock;
        vector<vector<string>> result;
        for (string str : strs) {
            int sum_str = 0;
            for (char c : str) sum_str += static_cast<int>(c);
            if (stock.find(sum_str) != stock.end()) {
                string& taken_str = result[stock[sum_str]][0];
                if (taken_str.size() != str.size()) continue;
                if (str.empty()) {
                    result[stock[sum_str]].push_back(str);
                    continue;
                }
                for (char c : taken_str) {
                    if (str.find(c) == string::npos) {
                        result.push_back({str});
                        stock[sum_str] = result.size() - 1;
                        break;
                    }
                    if (c == taken_str.back()) result[stock[sum_str]].push_back(str);
                }
            }
            else {
                result.push_back({str});
                stock[sum_str] = result.size() - 1;
            }
        }
        return result;
    }
};
// @lc code=end
