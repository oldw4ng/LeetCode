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
    TreeNode* recoverFromPreorder(string S) {
        if (!S.size()) {
            return nullptr;
        }
        return go(S, 0);
    }
    
    TreeNode* go(string& S, size_t depth) {
        TreeNode* p = new TreeNode(getNum(S));
        size_t i = 0;
        while (S[i] == '-') {
            i++;
        }
        if (i > depth) {
            S = S.substr(i);
            p -> left = go(S, depth + 1);
        }
        i = 0;
        while (S[i] == '-') {
            i++;
        }
        if (i > depth) {
            S = S.substr(i);
            p -> right = go(S, depth + 1);
        }
        return p;
    }
    
    int getNum(string &S) {
        int res = 0, i = 0;
        while (i < S.size() && S[i] >= '0' && S[i] <= '9') {
            res = 10 * res + S[i] - '0';
            i++;
        }
        S = S.substr(i);
        return res;
    }
};