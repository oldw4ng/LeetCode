/*
 * @lc app=leetcode id=1012 lang=cpp
 *
 * [1012] Numbers With Repeated Digits
 *
 * https://leetcode.com/problems/numbers-with-repeated-digits/description/
 *
 * algorithms
 * Hard (35.26%)
 * Likes:    90
 * Dislikes: 31
 * Total Accepted:    2.9K
 * Total Submissions: 8.2K
 * Testcase Example:  '20'
 *
 * Given a positive integer N, return the number of positive integers less than
 * or equal to N that have at least 1 repeated digit.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 20
 * Output: 1
 * Explanation: The only positive number (<= 20) with at least 1 repeated digit
 * is 11.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 100
 * Output: 10
 * Explanation: The positive numbers (<= 100) with atleast 1 repeated digit are
 * 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 1000
 * Output: 262
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 10^9
 * 
 * 
 * 
 */
class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        int ret = 0;
        vector<int> v;
        for (int x = N + 1; x; x /= 10) {
            v.push_back(x % 10);
        }
        reverse(v.begin(), v.end());

        decltype(v.size()) size = v.size();
        for (int i = 0; i < size - 1; ++i) {
            ret += 9 * A(9, i);
        }
        bool invalid = true;
        for (int i = 0; i < size; ++i) {
            int cnt = 0;
            for (int j = 0; j < i; ++j) {
                if (v[i] == v[j]) {
                    invalid = false;
                }
                if (v[i] >= v[j]) {
                    cnt++;
                }
            }
            ret += (v[i] - cnt - (i? 0: 1) + (invalid? 0: 1)) * A(9 - i , size - i - 1);
            if (!invalid) {
                break;
            }
        }
        
        
        return N - ret;
    }
    
    int A(int x, int y) {
        return y? x * A(x - 1, y - 1): 1;
    }
};

