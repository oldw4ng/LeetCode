/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (34.04%)
 * Likes:    1886
 * Dislikes: 842
 * Total Accepted:    310.6K
 * Total Submissions: 911.5K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Note:
 * 
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> table;
    string addstring(string num1, string num2) {
        if (num1.size() < num2.size()) {
            swap(num1, num2);
        }
        string zeros(num1.size() - num2.size(), '0');
        num2 = zeros + num2;
        string ret = "";
        int carry = 0;
        int cur = 0;
        for (int i = num1.size() - 1; i >= 0; --i) {
            cur = num1[i] + num2[i] - '0' - '0' + carry;
            carry = cur / 10;
            ret = string(1, (cur % 10) + '0') + ret;
        }
        if (carry)
            ret = "1" + ret;
        return ret;
    }

    void generate_multitable(string num1) {
        //table = vector<string>(10);
        table[0] = "0";
        table[1] = num1;
        for (size_t i = 2; i < 10; i++) {
            table[i] = "0";
            for (int j = 0; j < i; ++j) {
                table[i] = addstring(table[i], num1);
            }
        }
    }

    string multiply(string num1, string num2) {
        table = vector<string>(10);
        generate_multitable(num1);
        string ret = "0";
        for (int i = 0; i < num2.size(); ++i) {
            ret = ret + "0";
            ret = addstring(ret, table[num2[i] - '0']);
        }
        for (int i = 0; i < ret.size(); ++i) {
            if (ret[i] != '0')
                return ret.substr(i);
        }
        return "0";
    }
};
// @lc code=end

