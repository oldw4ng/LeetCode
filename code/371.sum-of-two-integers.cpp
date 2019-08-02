/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 *
 * https://leetcode.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Easy (50.86%)
 * Likes:    806
 * Dislikes: 1461
 * Total Accepted:    142K
 * Total Submissions: 279.2K
 * Testcase Example:  '1\n2'
 *
 * Calculate the sum of two integers a and b, but you are not allowed to use
 * the operator + and -.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: a = 1, b = 2
 * Output: 3
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: a = -2, b = 3
 * Output: 1
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int getSum(int a, int b) {
        int ret = 0, i = 1, carry = 0;
        while (i) {
            if ((a & i) & (b & i)) {
                ret = ((a & i) ^ (b & i)) ^ carry ^ ret;
                carry = ((a & i) & (b & i)) << 1;
            } else if ((a & i) ^ (b & i)) {
                ret = ((a & i) ^ (b & i)) ^ carry ^ ret;
                carry = (((a & i) ^ (b & i)) & carry) << 1;
            } else {
                ret = carry ^ ret;
                carry = 0;
            }
            i = i << 1;
        }
        return ret;
    }
};

