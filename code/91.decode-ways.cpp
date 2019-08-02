/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (22.63%)
 * Likes:    1513
 * Dislikes: 1762
 * Total Accepted:    277.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 * 
 * Example 1:
 * 
 * 
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 * 
 */
class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0) {
            return 0;
        }
        
        vector<int> v(s.size() + 1);
        v[s.size()] = 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                v[i] = 0;
            } else {
                v[i] = v[i + 1];
                if (i < s.size() - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7')) {
                    v[i] += v[i+2];
                }
            }
            
        }
        return v[0];
    }
};

