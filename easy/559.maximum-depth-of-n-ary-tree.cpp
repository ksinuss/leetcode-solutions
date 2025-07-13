/*
 * @lc app=leetcode id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
 */

// @lc code=start

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        return 1 + accumulate(
            root->children.begin(), root->children.end(),
            0,
            [&](int current_max, Node* child) {
                return std::max(current_max, maxDepth(child));
            }
        );
    }
};
// @lc code=end
