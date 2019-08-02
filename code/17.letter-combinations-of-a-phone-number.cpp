/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (42.38%)
 * Likes:    2400
 * Dislikes: 321
 * Total Accepted:    420.4K
 * Total Submissions: 991.9K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
class Solution {
    const string num_char[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (!digits.size()) return result;
        if (digits.size() == 1) {
            for (int i = 0; i < num_char[digits[0] - '0'].size(); i++) {
                result.push_back(num_char[digits[0] - '0'].substr(i, 1));
            }
            return result;
        }
        vector<string> v = letterCombinations(digits.substr(1, digits.size() - 1));
        for (int i = 0; i < num_char[digits[0] - '0'].size(); i++) {
            for (string &s : v) {
                result.push_back(num_char[digits[0] - '0'].substr(i, 1) + s);
            }
        }
        return result;
    }
};



