/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (29.50%)
 * Likes:    1176
 * Dislikes: 425
 * Total Accepted:    254.5K
 * Total Submissions: 862.6K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 * 
 */
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrimes(n, true);
        int ret = 0;
        for (int i = 2; i < n; i++) {
            if (isPrimes[i]) {
                ret++;
                for (int j = 2; j * i < n; j++) {
                    isPrimes[j * i] = false;
                }
            }
        }
        return ret;
    }
};

