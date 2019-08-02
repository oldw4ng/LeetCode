/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (56.10%)
 * Likes:    3030
 * Dislikes: 189
 * Total Accepted:    367.7K
 * Total Submissions: 655.4K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        add(result, "", n, 0);
        return result;
    }
    
    void add(vector<string> &res, string s, int left, int right) {
        if (!left && !right) {
            res.push_back(s);
            return;
        }
        if (right > 0) {
            add(res, s + ")", left, right - 1);
        }
        if (left > 0) {
            add(res, s + "(", left - 1, right + 1);
        }
    }
};

