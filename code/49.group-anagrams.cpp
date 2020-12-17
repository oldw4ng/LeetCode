/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (58.33%)
 * Likes:    4520
 * Dislikes: 213
 * Total Accepted:    807.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings strs, group the anagrams together. You can return
 * the answer in any order.
 * 
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 * 
 * 
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * Example 2:
 * Input: strs = [""]
 * Output: [[""]]
 * Example 3:
 * Input: strs = ["a"]
 * Output: [["a"]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] consists of lower-case English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(const vector<string>& strs) {
        auto myHash = [](const array<int, 26>& arr) -> size_t {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ std::hash<int>()(num);
            });
        };

        unordered_map<array<int, 26>, vector<string>, decltype(myHash)> groups(0, myHash);
        for (auto str : strs) {
            array<int, 26> cnts{};
            for (auto c : str) {
                cnts[c - 'a']++;
            }
            groups[cnts].push_back(str);
        }
        vector<vector<string>> ret;
        for (auto group : groups) {
            ret.push_back(group.second);
        }
        return ret;
    }
};
// @lc code=end

