/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (63.47%)
 * Likes:    4670
 * Dislikes: 93
 * Total Accepted:    660.5K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int size = pow(2, nums.size());
        for (int i = 0; i < size; ++i) {
            vector<int> v;
            for (int j = 0; j < nums.size(); ++j) {
                if ((1 << j) & i)
                    v.push_back(nums[j]);
            }
            res.push_back(v);
        }
        return res;
    }
};
// @lc code=end

