/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
 *
 * https://leetcode.com/problems/find-bottom-left-tree-value/description/
 *
 * algorithms
 * Medium (58.93%)
 * Likes:    603
 * Dislikes: 105
 * Total Accepted:    76.8K
 * Total Submissions: 130.2K
 * Testcase Example:  '[2,1,3]'
 *
 * 
 * Given a binary tree, find the leftmost value in the last row of the tree. 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 
 * Output:
 * 1
 * 
 * 
 * 
 * ⁠ Example 2: 
 * 
 * Input:
 * 
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 * ⁠    /   / \
 * ⁠   4   5   6
 * ⁠      /
 * ⁠     7
 * 
 * Output:
 * 7
 * 
 * 
 * 
 * Note:
 * You may assume the tree (i.e., the given root node) is not NULL.
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    string getDepth(TreeNode* root) {
        if (!root) {
            return "";
        }
        string leftPath = getDepth(root -> left);
        string rightPath = getDepth(root -> right);
        if (leftPath.size() >= rightPath.size()) {
            return "0" + leftPath;
        }
        return "1" + rightPath;
    }
    
    int findBottomLeftValue(TreeNode* root) {
        string path = getDepth(root);
        for (int i = 0; i < path.size() - 1; ++i) {
            root = path[i] == '0'? root -> left: root -> right;
        }
        return root -> val;
    }
};

