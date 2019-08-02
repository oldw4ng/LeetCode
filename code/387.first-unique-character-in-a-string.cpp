/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (50.40%)
 * Likes:    1104
 * Dislikes: 84
 * Total Accepted:    294.8K
 * Total Submissions: 584.9K
 * Testcase Example:  '"leetcode"'
 *
 * 
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contain only lowercase letters.
 * 
 */
class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            arr[s[i] - 'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (arr[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};


