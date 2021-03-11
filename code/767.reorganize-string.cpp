/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 *
 * https://leetcode.com/problems/reorganize-string/description/
 *
 * algorithms
 * Medium (49.45%)
 * Likes:    2229
 * Dislikes: 106
 * Total Accepted:    109.8K
 * Total Submissions: 221.3K
 * Testcase Example:  '"aab"'
 *
 * Given a string S, check if the letters can be rearranged so that two
 * characters that are adjacent to each other are not the same.
 * 
 * If possible, output any possible result.  If not possible, return the empty
 * string.
 * 
 * Example 1:
 * 
 * 
 * Input: S = "aab"
 * Output: "aba"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: S = "aaab"
 * Output: ""
 * 
 * 
 * Note:
 * 
 * 
 * S will consist of lowercase letters and have length in range [1, 500].
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string reorganizeString(string S) {
        auto size = S.size();
        vector<int> f(26, 0);
        for (auto c : S)
            f[c - 'a']++;
        for (auto n : f) {
            if (n > ((S.size() + 1) / 2))
                return "";
        }
        string ret(S.size(), ' ');
        int odd = 1, even = 0;
        for (int i = 0; i < 26; ++i) {
            auto c = i + 'a';
            while (f[i] > 0 && f[i] <= S.size() / 2 && odd < S.size()) {
                f[i]--;
                ret[odd] = c;
                odd += 2;
            }
            while (f[i] > 0) {
                f[i]--;
                ret[even] = c;
                even += 2;
            }
        }
        return ret;
    }
};
// @lc code=end

