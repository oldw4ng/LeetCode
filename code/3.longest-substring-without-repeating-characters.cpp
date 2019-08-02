/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.65%)
 * Likes:    5957
 * Dislikes: 341
 * Total Accepted:    1M
 * Total Submissions: 3.6M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        queue<char> tempLS;
        map<char, int> map;
        for (int i = 0; i < s.size(); i++) {
            if (!map.count(s[i])) {
                map.insert(pair<char, int>(s[i], i));
                tempLS.push(s[i]);
            }else {
                result = result > tempLS.size()? result: tempLS.size();
                while (!tempLS.empty()) {
                    if (tempLS.front() != s[i]) {
                        map.erase(tempLS.front());
                        tempLS.pop();
                    }else {
                        map.erase(tempLS.front());
                        tempLS.pop();
                        break;
                    }
                }
                map.insert(pair<char, int>(s[i], i));
                tempLS.push(s[i]);
            }
        }
        result = result >= tempLS.size()? result: tempLS.size();
        return result;
    }
};

