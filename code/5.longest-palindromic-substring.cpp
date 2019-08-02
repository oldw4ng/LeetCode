/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (27.65%)
 * Likes:    4002
 * Dislikes: 376
 * Total Accepted:    610.6K
 * Total Submissions: 2.2M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        char *str = new char[2 * size + 1];
        int *p_length = new int[2 * size + 1];
        int max_pos = 0;
        for (int i = 0; i <= size; i++) {
            str[2 * i] = '#';
        }
        for (int i = 0; i < size; ++i) {
            str[2 * i + 1] = s[i];
        }
        for (int i = 0; i <= 2 * size; i++) {
            p_length[i] = 1;
        }
        for (int i = 0; i <= 2 * size; i++) {
            for (int j = 1; (i - j) >= 0 && (i + j) <= 2 * size && str[i - j] == str[i + j]; j++) {
                p_length[i]++;
            }
            p_length[max_pos] > p_length[i]? max_pos = max_pos: max_pos = i;
        }
        
        char *result = new char[p_length[max_pos] - 1];
        for (int i = max_pos - p_length[max_pos] + 2, j = 0; i <= max_pos + p_length[max_pos] - 1; i += 2) {
            result[j++] = str[i];
        }
        return s.substr((max_pos - p_length[max_pos] + 1)/2, p_length[max_pos] - 1);
    }
};

