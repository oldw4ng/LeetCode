/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (49.98%)
 * Likes:    4075
 * Dislikes: 109
 * Total Accepted:    407.8K
 * Total Submissions: 814.8K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0)
            return nullptr;
        int root_val = preorder[0];
        TreeNode* root = new TreeNode(root_val);
        if (preorder.size() == 1)
            return root;
        auto it = find(inorder.begin(), inorder.end(), root_val);
        int pos = distance(inorder.begin(), it);
        vector<int> pre_left(preorder.begin() + 1, preorder.begin() + pos + 1);
        vector<int> pre_right(preorder.begin() + pos + 1, preorder.end());
        vector<int> in_left(inorder.begin(), inorder.begin() + pos);
        vector<int> in_right(inorder.begin() + pos + 1, inorder.end());
        root -> left = buildTree(pre_left, in_left);
        root -> right = buildTree(pre_right, in_right);
        return root;
    }
};
// @lc code=end

