/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (28.32%)
 * Likes:    907
 * Dislikes: 2233
 * Total Accepted:    342.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (x^n).
 * 
 * Example 1:
 * 
 * 
 * Input: 2.00000, 10
 * Output: 1024.00000
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2.10000, 3
 * Output: 9.26100
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 
 * Note:
 * 
 * 
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
 * 
 * 
 */
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (x == 1) {
            return 1;
        }
        if (x == -1) {
            return n % 2? -1: 1;
        }
        
        double ret = 1;
        if (n == INT_MIN) {
            ret = 1 / x;
            for (int i = 0; i < 32; i++) {
                ret *= ret;
            }
            return ret;
        }
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        vector<double> v;
        for (int i = 0; i < 31; i++) {
            v.push_back(x);
            x *= x;
        }
        for (int i = 0; i < 31; i++) {
            ret *= ((n >> i) & 1)? v[i]: 1;
        }
        return ret;
    }
};

