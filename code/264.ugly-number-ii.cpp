/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (36.96%)
 * Likes:    995
 * Dislikes: 70
 * Total Accepted:    110.2K
 * Total Submissions: 298.3K
 * Testcase Example:  '10'
 *
 * Write a program to find the n-th ugly number.
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3,
 * 5. 
 * 
 * Example:
 * 
 * 
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 * 
 * Note:  
 * 
 * 
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 * 
 */
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        vector<int> num(n);
        num[0] = 1;
        int t2 = 0, t3 = 0, t5 = 0;
        for (int i = 1; i < n; i++) {
            num[i] = min(num[t2] * 2, min(num[t3] * 3, num[t5] * 5));
            if (num[i] == num[t2] * 2) t2++;
            if (num[i] == num[t3] * 3) t3++;
            if (num[i] == num[t5] * 5) t5++;
        }
        return num[n - 1];
    }
};

