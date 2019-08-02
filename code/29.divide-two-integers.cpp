/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (16.16%)
 * Likes:    725
 * Dislikes: 3482
 * Total Accepted:    207.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division and mod operator.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * The integer division should truncate toward zero.
 * 
 * Example 1:
 * 
 * 
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * 
 * Note:
 * 
 * 
 * Both dividend and divisor will be 32-bit signed integers.
 * The divisor will never be 0.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 2^31 − 1 when the
 * division result overflows.
 * 
 * 
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int result = 0;
        bool dividend_negative = dividend < 0, divisor_negative = divisor < 0;

        int size_dividend = 0, size_divisor = 0;
        long long a = dvd;
        while (a) {
            size_dividend++;
            a = a >> 1;
        }
        a = dvs;
        while (a) {
            size_divisor++;
            a = a >> 1;
        }
        long long current = 0;
        for (int i = 1; i <= size_dividend; i++) {
            current = dvd >> (size_dividend - i);
            result = result << 1;
            if (current >= dvs) {
                result += 1;
                dvd -= dvs << (size_dividend - i);
            }
        }
        return dividend_negative ^ divisor_negative? -result: result;
    }
};

