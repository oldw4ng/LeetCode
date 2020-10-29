/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (49.17%)
 * Likes:    2180
 * Dislikes: 75
 * Total Accepted:    360.1K
 * Total Submissions: 730.6K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sum to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note: The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
 * Output: 
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5
 * Output: 
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> cur;
        combinationSum2(candidates, ret, cur, target, 0);
        return ret;
    }
    void combinationSum2(vector<int>& candidates, vector<vector<int>>& ret, vector<int>& cur, int target, int begin) {
        if (!target) {
            ret.push_back(cur);
            return;
        }
        for (int i = begin; i < candidates.size() && target >= candidates[i]; ++i) {
            if (i == begin || candidates[i] != candidates[i - 1]) {
                cur.push_back(candidates[i]);
                combinationSum2(candidates, ret, cur, target - candidates[i], i + 1);
                cur.pop_back();
            }
        }
    }

};
// @lc code=end

