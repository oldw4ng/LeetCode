/*
 * @lc app=leetcode id=1016 lang=cpp
 *
 * [1016] Binary String With Substrings Representing 1 To N
 *
 * https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/description/
 *
 * algorithms
 * Medium (59.78%)
 * Likes:    49
 * Dislikes: 185
 * Total Accepted:    7.8K
 * Total Submissions: 13.1K
 * Testcase Example:  '"0110"\n3'
 *
 * Given a binary string S (a string consisting only of '0' and '1's) and a
 * positive integer N, return true if and only if for every integer X from 1 to
 * N, the binary representation of X is a substring of S.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: S = "0110", N = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: S = "0110", N = 4
 * Output: false
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= S.length <= 1000
 * 1 <= N <= 10^9
 * 
 * 
 */
class Solution {
public:
    bool queryString(string S, int N) {
        for (int i = 1; i <= N; ++i) {
            string _s = "";
            int x = i;
            while (x) {
                _s += x % 2 + '0';
                x /= 2;
            }
            reverse(_s.begin(), _s.end());
            if (S.find(_s) == string::npos) {
                return false;
            }
        }
        return true;
    }
};

