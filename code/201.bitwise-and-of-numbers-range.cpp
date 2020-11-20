/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 *
 * https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
 *
 * algorithms
 * Medium (39.52%)
 * Likes:    1178
 * Dislikes: 131
 * Total Accepted:    162.5K
 * Total Submissions: 411K
 * Testcase Example:  '5\n7'
 *
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND
 * of all numbers in this range, inclusive.
 * 
 * Example 1:
 * 
 * 
 * Input: [5,7]
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [0,1]
 * Output: 0
 */

// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        return m < n? rangeBitwiseAnd(m, n & (n - 1)): n;
    }
};
// @lc code=end

