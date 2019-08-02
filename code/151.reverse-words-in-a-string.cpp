/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (17.33%)
 * Likes:    607
 * Dislikes: 2343
 * Total Accepted:    296.6K
 * Total Submissions: 1.7M
 * Testcase Example:  '"the sky is blue"'
 *
 * Given an input string, reverse the string word by word.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "the sky is blue"
 * Output: "blue is sky the"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "  hello world!  "
 * Output: "world! hello"
 * Explanation: Your reversed string should not contain leading or trailing
 * spaces.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "a good   example"
 * Output: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to a
 * single space in the reversed string.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * A word is defined as a sequence of non-space characters.
 * Input string may contain leading or trailing spaces. However, your reversed
 * string should not contain leading or trailing spaces.
 * You need to reduce multiple spaces between two words to a single space in
 * the reversed string.
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * For C programmers, try to solve it in-place in O(1) extra space.
 */
class Solution {
public:
    string reverseWords(string s) {
        string ret = "";
        int i = s.size() - 1;
        while (i >= 0) {
            while (i >=0 && s[i] == ' ') {i--;}
            if (i < 0)
                break;
            int j = i;
            while (i >= 0 && s[i] != ' ') {i--;}
            if (ret == "") {
                ret = s.substr(i + 1, j - i);
            } else
                ret = ret + " " + s.substr(i + 1, j - i);
        }
        return ret;
    }
};

