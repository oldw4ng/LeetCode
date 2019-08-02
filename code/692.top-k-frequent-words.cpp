/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 *
 * https://leetcode.com/problems/top-k-frequent-words/description/
 *
 * algorithms
 * Medium (46.45%)
 * Likes:    821
 * Dislikes: 77
 * Total Accepted:    73K
 * Total Submissions: 157.2K
 * Testcase Example:  '["i", "love", "leetcode", "i", "love", "coding"]\n2'
 *
 * Given a non-empty list of words, return the k most frequent elements.
 * Your answer should be sorted by frequency from highest to lowest. If two
 * words have the same frequency, then the word with the lower alphabetical
 * order comes first.
 * 
 * Example 1:
 * 
 * Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
 * Output: ["i", "love"]
 * Explanation: "i" and "love" are the two most frequent words.
 * ⁠   Note that "i" comes before "love" due to a lower alphabetical order.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is",
 * "is"], k = 4
 * Output: ["the", "is", "sunny", "day"]
 * Explanation: "the", "is", "sunny" and "day" are the four most frequent
 * words,
 * ⁠   with the number of occurrence being 4, 3, 2 and 1 respectively.
 * 
 * 
 * 
 * Note:
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Input words contain only lowercase letters.
 * 
 * 
 * 
 * Follow up:
 * 
 * Try to solve it in O(n log k) time and O(n) extra space.
 * 
 * 
 */
bool cmp(const pair<string, int> &p1, const pair<string, int> &p2) {
    if (p1.second > p2.second) {
        return true;
    } else if (p1.second == p2.second)
        return p1.first < p2.first;
    return false;
}
class Solution {
public:
    
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        for (vector<string>::iterator i = words.begin(); i != words.end(); i++) {
            if (!m.count(*i)) {
                m[*i] = 1;
                continue;
            }
            m[*i]++;
        }
        vector<pair<string, int>> arr;
        for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
            arr.push_back(make_pair(it->first, it->second));
        }
        sort(arr.begin(), arr.end(), cmp);
        vector<string> ret;
        for (int i = 0; i < k; i++) {
            ret.push_back(arr[i].first);
        }
        return ret;
    }
};

