/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (38.17%)
 * Likes:    1602
 * Dislikes: 199
 * Total Accepted:    236.9K
 * Total Submissions: 620.5K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string s, find if s follows the same pattern.
 * 
 * Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in s.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: pattern = "abba", s = "dog cat cat dog"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: pattern = "abba", s = "dog cat cat fish"
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: pattern = "aaaa", s = "dog cat cat dog"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: pattern = "abba", s = "dog dog dog dog"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= pattern.length <= 300
 * pattern contains only lower-case English letters.
 * 1 <= s.length <= 3000
 * s contains only lower-case English letters and spaces ' '.
 * s does not contain any leading or trailing spaces.
 * All the words in s are separated by a single space.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> word_list;
        unordered_map<char, string> pattern_list;
        int i = 0;
        for (auto c: pattern) {
            if (i > s.size())
                return false;
            string word = "";
            int j = i;
            for (; j < s.size() && s[j] != ' '; ++j) {
                word += s[j];
            }
            i = j + 1;
            if (word_list.count(word)) {
                if (word_list[word] != c)
                    return false;
                continue;
            }
            if (pattern_list.count(c)) {
                return false;
            }
            word_list[word] = c;
            pattern_list[c] = word;
        }
        return i >= s.size();
    }
};
// @lc code=end

