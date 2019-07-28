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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* p = root;
        stack<TreeNode*> s;
        s.push(p);
        while(!s.empty()) {
            p = s.top();
            s.pop();
            if (p) {
                res.push_back(p -> val);
                s.push(p -> right);
                s.push(p -> left);
            }
        }
        return res;
    }
};