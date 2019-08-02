/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (36.93%)
 * Likes:    3172
 * Dislikes: 150
 * Total Accepted:    649K
 * Total Submissions: 1.8M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> _stack;
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
                case '(':
                    _stack.push(')');
                    break;
                case '[':
                    _stack.push(']');
                    break;
                case '{':
                    _stack.push('}');
                    break;
                default:
                    if (_stack.empty() || _stack.top() != s[i]) {
                        return false;
                    }
                    _stack.pop();
                    break;
            }
        }
        return _stack.empty();
    }
};

