/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (48.99%)
 * Likes:    2639
 * Dislikes: 108
 * Total Accepted:    425.9K
 * Total Submissions: 868.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        vector<queue<TreeNode*>> queues(2);
        if (!root)
            return ret;
        queues[0].push(root);
        uint8_t n = 0;
        while (!queues[0].empty() || !queues[1].empty()) {
            vector<int> cur;
            while (!queues[n].empty()) {
                auto node = queues[n].front();
                cur.push_back(node -> val);
                if (node -> left)
                    queues[!n].push(node -> left);
                if (node -> right)
                    queues[!n].push(node -> right);
                queues[n].pop();
            }
            if (n)
                reverse(cur.begin(), cur.end());
            ret.push_back(cur);
            n = !n;
        }
        return ret;
    }
};
// @lc code=end

