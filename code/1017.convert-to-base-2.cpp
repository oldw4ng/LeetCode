/*
 * @lc app=leetcode id=1017 lang=cpp
 *
 * [1017] Convert to Base -2
 *
 * https://leetcode.com/problems/convert-to-base-2/description/
 *
 * algorithms
 * Medium (57.24%)
 * Likes:    82
 * Dislikes: 98
 * Total Accepted:    6.5K
 * Total Submissions: 11.4K
 * Testcase Example:  '2'
 *
 * Given a number N, return a string consisting of "0"s and "1"s that
 * represents its value in base -2 (negative two).
 * 
 * The returned string must have no leading zeroes, unless the string is
 * "0".
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: "110"
 * Explantion: (-2) ^ 2 + (-2) ^ 1 = 2
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 3
 * Output: "111"
 * Explantion: (-2) ^ 2 + (-2) ^ 1 + (-2) ^ 0 = 3
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 4
 * Output: "100"
 * Explantion: (-2) ^ 2 = 4
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= N <= 10^9
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    string baseNeg2(int N) {
        if ( N == 0) {
            return "0";
        }
        string ret = "";
        while (N) {
            if (N % -2) {
                ret = "1" + ret;
                if (N > 0) {
                    N = N / -2;
                } else {
                    N = (N / -2) + 1;
                }
            } else {
                ret = "0" + ret;
                N /= -2;
            }
        }
        return ret;
    }
};

