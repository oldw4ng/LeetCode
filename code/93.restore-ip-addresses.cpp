/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (32.03%)
 * Likes:    719
 * Dislikes: 297
 * Total Accepted:    146.8K
 * Total Submissions: 458.4K
 * Testcase Example:  '"25525511135"'
 *
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 * 
 * Example:
 * 
 * 
 * Input: "25525511135"
 * Output: ["255.255.11.135", "255.255.111.35"]
 * 
 * 
 */
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        int i = 0, size = s.size();
        if (size < 4) {
            return ret;
        }
        int x, y, z;
        string str = "";
        for (x = max(1, size - 9); x <= min(3, size - 3); x++) {
            if (isValid(s.substr(0, x))) {
                for (y = max(x + 1, size - 6); y <= min(x + 3, size - 2); y++) {
                    if (isValid(s.substr(x, y - x))) {
                        for (z = max(y + 1, size - 3); z <= min(y + 3, size - 1); z++) {
                            if (size - z > 3)
                                continue;
                            if (isValid(s.substr(y, z - y)) && isValid(s.substr(z, size - z))) {
                                str = s.substr(0, x) + "." + s.substr(x, y - x) + "." + s.substr(y, z - y) + "." + s.substr(z, size - z);
                                ret.push_back(str);
                                str = "";
                            }
                        }
                    }
                }
            }
        }
        return ret;
    }
    
    bool isValid(string s) {
        return s.size() == 1 || (s.size() == 2 && s[0] != '0') || (stoi(s) <= 255 && s[0] != '0');
    }
};
