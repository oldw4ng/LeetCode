/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (44.21%)
 * Likes:    1535
 * Dislikes: 1341
 * Total Accepted:    633.1K
 * Total Submissions: 1.4M
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 * 
 * Example 1:
 * 
 * 
 * Input: 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Follow up:
 * 
 * Coud you solve it without converting the integer to a string?
 * 
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int size = 0;
        int t = x;
        while (t) {
            t = t / 10;
            size++;
        }
        int first = 0, last = size - 1;
        while (first <= last) {
            if (((x / (int)pow(10, first++)) % 10) != ((x / (int)pow(10, last--)) % 10)) {
                return false;
            }
        }
        return true;
    }
};

