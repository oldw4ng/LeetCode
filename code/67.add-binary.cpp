/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (39.92%)
 * Likes:    1070
 * Dislikes: 202
 * Total Accepted:    322.1K
 * Total Submissions: 806.8K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */
class Solution {
public:
    string addBinary(string a, string b) {
        size_t aSize = a.size(), bSize = b.size();
        string ret = "";
        int add = 0;
        int i, j;
        for (i = aSize - 1, j = bSize - 1; i >= 0 && j >= 0; --i, --j) {
            char thisC = (a[i] + b[j] - '0' - '0' + add) % 2 + '0';
            add = (a[i] + b[j] - '0' - '0' + add) / 2;
            ret = thisC + ret;
        }
        for (; i >= 0; --i) {
            char thisC = (a[i] - '0' + add) % 2 + '0';
            add = (a[i] - '0' + add) / 2;
            ret = thisC + ret;
        }
        for (; j >= 0; --j) {
            char thisC = (b[j] - '0' + add) % 2 + '0';
            add = (b[j] - '0' + add) / 2;
            ret = thisC + ret;
        }
        if (add) {
            ret = "1" + ret;
        }
        return ret;
    }
};

