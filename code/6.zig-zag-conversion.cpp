/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (32.66%)
 * Likes:    1120
 * Dislikes: 3449
 * Total Accepted:    342.1K
 * Total Submissions: 1M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if (s.size() == 0 || numRows == 1) {
            return s;
        }
        string *l = new string[numRows];
        int i = 0, j = 0;
        bool up = false, down = true;
        while (i < s.size()) {
            while (down && i < s.size()) {
                l[j++] += s.substr(i++,1);
                if (j == numRows - 1) {
                    down = false;
                    up = true;
                }
            }
            while (up && i < s.size()) {
                l[j--] += s.substr(i++,1);
                if (j == 0) {
                    up = false;
                    down = true;
                }
            }
        }
        string ret = "";
        for (int i = 0; i < numRows; i++) {
            if (l[i].size()) {
                ret += l[i];
            }
        }
        return ret;
    }
};

