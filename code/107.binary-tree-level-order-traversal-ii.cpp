/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (54.15%)
 * Likes:    1730
 * Dislikes: 225
 * Total Accepted:    379.4K
 * Total Submissions: 699.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
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
 * return its bottom-up level order traversal as:
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
// @lc code=end

