/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
using namespace std;
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_info;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freq_elements;
        for (int n : nums) ++freq_info[n];
        for (auto i : freq_info) {
            freq_elements.push({i.second, i.first});
            if (freq_elements.size() > k) freq_elements.pop();
        }
        vector<int> result;
        while (!freq_elements.empty()) {
            result.push_back(freq_elements.top().second);
            freq_elements.pop();
        } 
        return result;
    }
};
// @lc code=end
