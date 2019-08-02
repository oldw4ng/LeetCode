/*
 * @lc app=leetcode id=1023 lang=cpp
 *
 * [1023] Camelcase Matching
 *
 * https://leetcode.com/problems/camelcase-matching/description/
 *
 * algorithms
 * Medium (56.19%)
 * Likes:    78
 * Dislikes: 75
 * Total Accepted:    8.8K
 * Total Submissions: 15.7K
 * Testcase Example:  '["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"]\n"FB"'
 *
 * A query word matches a given pattern if we can insert lowercase letters to
 * the pattern word so that it equals the query. (We may insert each character
 * at any position, and may insert 0 characters.)
 * 
 * Given a list of queries, and a pattern, return an answer list of booleans,
 * where answer[i] is true if and only if queries[i] matches the pattern.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: queries =
 * ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern =
 * "FB"
 * Output: [true,false,true,true,false]
 * Explanation: 
 * "FooBar" can be generated like this "F" + "oo" + "B" + "ar".
 * "FootBall" can be generated like this "F" + "oot" + "B" + "all".
 * "FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".
 * 
 * Example 2:
 * 
 * 
 * Input: queries =
 * ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern =
 * "FoBa"
 * Output: [true,false,true,false,false]
 * Explanation: 
 * "FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
 * "FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: queries =
 * ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern =
 * "FoBaT"
 * Output: [false,true,false,false,false]
 * Explanation: 
 * "FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" +
 * "est".
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= queries.length <= 100
 * 1 <= queries[i].length <= 100
 * 1 <= pattern.length <= 100
 * All strings consists only of lower and upper case English letters.
 * 
 */
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ret;
        for (auto item : queries) {
            ret.push_back(judge(item, pattern));
        }
        return ret;
    }
    
    bool judge(string s, string p) {
        string str;
        int i = 0, j = 0;
        for (; i < s.size() && j < p.size(); ) {
            if (s[i] == p[j]) {
                i++;
                j++;
            } else {
                str += s[i++];
            }
        }
        while (i < s.size()) {
            str += s[i++];
        }
        if (j < p.size()) {
            return false;
        }
        for (i = 0; i < str.size(); ++i) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                return false;
            }
        }
        return true;
    }
};


