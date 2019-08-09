/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (31.43%)
 * Likes:    2566
 * Dislikes: 171
 * Total Accepted:    258.6K
 * Total Submissions: 820.6K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * Example:
 * 
 * 
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * 
 * 
 * Note:
 * 
 * 
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 * 
 * 
 */
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;
        for (char c : t) {
            freq[c]++;
        }
        int begin = 0, end = 0, diff = INT_MAX, cnt = t.size(), head = 0;
        while (end < s.size()) {
            if (freq.count(s[end]) && freq[s[end]]-- > 0) {
                cnt--;
            }
            end++;
            while (cnt == 0) {
                if (end - begin < diff) {
                    diff = end - begin;
                    head = begin;
                }
                if (freq.count(s[begin]) && freq[s[begin]]++ == 0) {
                    cnt++;
                }
                begin++;
            }
        }
        return diff == INT_MAX? "": s.substr(head, diff);
    }
};

