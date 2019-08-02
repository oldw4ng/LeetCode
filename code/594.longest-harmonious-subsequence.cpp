/*
 * @lc app=leetcode id=594 lang=cpp
 *
 * [594] Longest Harmonious Subsequence
 *
 * https://leetcode.com/problems/longest-harmonious-subsequence/description/
 *
 * algorithms
 * Easy (44.30%)
 * Likes:    438
 * Dislikes: 61
 * Total Accepted:    39.4K
 * Total Submissions: 88.8K
 * Testcase Example:  '[1,3,2,2,5,2,3,7]'
 *
 * We define a harmounious array as an array where the difference between its
 * maximum value and its minimum value is exactly 1.
 * 
 * Now, given an integer array, you need to find the length of its longest
 * harmonious subsequence among all its possible subsequences.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,2,2,5,2,3,7]
 * Output: 5
 * Explanation: The longest harmonious subsequence is [3,2,2,2,3].
 * 
 * 
 * 
 * 
 * Note: The length of the input array will not exceed 20,000.
 * 
 */
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> m;
        for (auto n : nums) {
            m[n]++;
        }
        int ret = 0;
        for (auto it : m) {
            if (m.count(it.first - 1)) {
                ret = max(ret, it.second + m[it.first - 1]);
            }
        }
        return ret;
    }
};

