/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (64.73%)
 * Likes:    4738
 * Dislikes: 115
 * Total Accepted:    691K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> cur;
        vector<bool> used(nums.size(), 0);
        dfs(ret, used, nums, cur);
        return ret;
    }

    void dfs(vector<vector<int>>& ret, vector<bool>& used, vector<int>& nums, vector<int>& cur) {
        if (cur.size() == nums.size()) {
            ret.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i])
                continue;
            cur.push_back(nums[i]);
            used[i] = true;
            dfs(ret, used, nums, cur);
            used[i] = false;
            cur.pop_back();
        }
    }
};
// @lc code=end

