/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.27%)
 * Likes:    408
 * Dislikes: 1697
 * Total Accepted:    284.3K
 * Total Submissions: 880.8K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ret = 0;
        int i = s.size() - 1;
        while (i >= 0 && s[i] == ' ')
            i--;
        for (; i >= 0; i--) {
            if(s[i] != ' ')
                ret++;
            else
                return ret;
        }
        return ret;
    }
};

