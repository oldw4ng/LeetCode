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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* p = root;
        stack<TreeNode*> s;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p -> left;
            }
            if (!s.empty()) {
                p = s.top();
                s.pop();
                res.push_back(p -> val);
                p = p -> right;
            }
        }
        return res;
    }
};