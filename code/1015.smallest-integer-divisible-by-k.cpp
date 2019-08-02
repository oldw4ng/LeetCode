/*
 * @lc app=leetcode id=1015 lang=cpp
 *
 * [1015] Smallest Integer Divisible by K
 *
 * https://leetcode.com/problems/smallest-integer-divisible-by-k/description/
 *
 * algorithms
 * Medium (29.01%)
 * Likes:    56
 * Dislikes: 173
 * Total Accepted:    6.1K
 * Total Submissions: 21.1K
 * Testcase Example:  '1'
 *
 * Given a positive integer K, you need find the smallest positive integer N
 * such that N is divisible by K, and N only contains the digit 1.
 * 
 * Return the length of N.  If there is no such N, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: 1
 * Explanation: The smallest answer is N = 1, which has length 1.
 * 
 * Example 2:
 * 
 * 
 * Input: 2
 * Output: -1
 * Explanation: There is no such positive integer N divisible by 2.
 * 
 * Example 3:
 * 
 * 
 * Input: 3
 * Output: 3
 * Explanation: The smallest answer is N = 111, which has length 3.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= K <= 10^5
 * 
 */
class Solution {
public:
    int smallestRepunitDivByK(int K) {
        int value = 0, length = 0;

        for (int i = 0; i < 1e6; i++) {
            value = (10 * value + 1) % K;
            length++;

            if (value == 0)
                return length;
        }

        return -1;
    }
};


