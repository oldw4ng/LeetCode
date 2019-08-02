/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (33.89%)
 * Likes:    1491
 * Dislikes: 1399
 * Total Accepted:    508.3K
 * Total Submissions: 1.5M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = "";
        int i = 0;
        int size = strs.size();
        if(!size)
            return ret;
        int minS = strs[0].size();
        for (int j = 1; j < size; j++) {
            minS = min(minS, (int)(strs[j].size()));
        }
        while (i < minS) {
            char c = strs[0][i];
            for (int j = 0; j < size; j++) {
                if (c != strs[j][i]) {
                    return ret;
                }
            }
            ret = ret + c;
            i++;
        }
        return ret;
    }
};

