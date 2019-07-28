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
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        calc(root, res);
        return res;
    }
    
    void calc(TreeNode* root, int &res) {
        if (root -> left) {
            root -> left -> val += root -> val * 2;
            calc(root -> left, res);
        }
        if (root -> right) {
            root -> right -> val += root -> val * 2;
            calc(root -> right, res);
        }
        if (!root -> left && !root -> right) {
            res += root -> val;
        }
    }
};