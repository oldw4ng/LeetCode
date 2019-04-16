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
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root -> val, root -> val);
    }

    int dfs (TreeNode* root, int minn, int maxx) {
        if (root) {
            minn = min(minn, root -> val);
            maxx = max(maxx, root -> val);
            return max(maxx - minn, max(dfs(root -> left, minn, maxx), dfs(root -> right, minn, maxx)));
        } else
            return 0;
    }

    // https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/discuss/274610/JavaC++Python-Top-Down
    int dfs_oneline (TreeNode* root, int minn, int maxx) {
        return root? max(max(root -> val - minn, maxx - root -> val),max(dfs_oneline(root -> left, min(minn, root -> val), max(maxx, root -> val)), dfs_oneline(root -> right, min(minn, root -> val), max(maxx, root -> val)))): 0;
    }

};