/*
 * @lc app=leetcode id=819 lang=cpp
 *
 * [819] Most Common Word
 *
 * https://leetcode.com/problems/most-common-word/description/
 *
 * algorithms
 * Easy (42.23%)
 * Likes:    339
 * Dislikes: 813
 * Total Accepted:    66.9K
 * Total Submissions: 158.3K
 * Testcase Example:  '"Bob hit a ball, the hit BALL flew far after it was hit."\n["hit"]'
 *
 * Given a paragraph and a list of banned words, return the most frequent word
 * that is not in the list of banned words.  It is guaranteed there is at least
 * one word that isn't banned, and that the answer is unique.
 * 
 * Words in the list of banned words are given in lowercase, and free of
 * punctuation.  Words in the paragraph are not case sensitive.  The answer is
 * in lowercase.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: 
 * paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
 * banned = ["hit"]
 * Output: "ball"
 * Explanation: 
 * "hit" occurs 3 times, but it is a banned word.
 * "ball" occurs twice (and no other word does), so it is the most frequent
 * non-banned word in the paragraph. 
 * Note that words in the paragraph are not case sensitive,
 * that punctuation is ignored (even if adjacent to words, such as "ball,"), 
 * and that "hit" isn't the answer even though it occurs more because it is
 * banned.
 * 
 * 
 * 
 * 
 * Note: 
 * 
 * 
 * 1 <= paragraph.length <= 1000.
 * 0 <= banned.length <= 100.
 * 1 <= banned[i].length <= 10.
 * The answer is unique, and written in lowercase (even if its occurrences in
 * paragraph may have uppercase symbols, and even if it is a proper noun.)
 * paragraph only consists of letters, spaces, or the punctuation symbols
 * !?',;.
 * There are no hyphens or hyphenated words.
 * Words only consist of letters, never apostrophes or other punctuation
 * symbols.
 * 
 * 
 */
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string, int> m;
        string ret = "";
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        size_t i = 0, size = paragraph.size();
        while (i < size) {
            while (i < size && !isLetter(paragraph[i])) {
                i++;
            }
            if (i >= size) {
                break;
            }
            size_t start = i;
            while (i < size && isLetter(paragraph[i])) {
                i++;
            }
            m[paragraph.substr(start, i - start)] ++;
        }
        for (auto item : banned) {
            m[item] = -1;
        }
        int maxnum = 0;
        for (auto item : m) {
            if (item.second > maxnum) {
                ret = item.first;
                maxnum = item.second;
            }
        }
        return ret;
    }
    
    bool isLetter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
};
