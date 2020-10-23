/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (55.38%)
 * Likes:    3608
 * Dislikes: 88
 * Total Accepted:    691.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
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
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
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
    vector<vector<int>> levelOrder(TreeNode* root) {
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
            ret.push_back(cur);
            n = !n;
        }
        return ret;
    }
};
// @lc code=end

