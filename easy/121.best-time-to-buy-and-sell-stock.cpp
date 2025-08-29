/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
using namespace std;
#include <vector>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int left_border = 0;
        int right_border = 1;
        while (right_border < prices.size()) {
            if (prices[right_border] < prices[left_border]) {
                left_border = right_border;
            }
            else if (prices[right_border] - prices[left_border] > max_profit) {
                max_profit = prices[right_border] - prices[left_border];
            }
            ++right_border;
        }
        return max_profit;
    }
};
// @lc code=end
