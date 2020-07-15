/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (60.42%)
 * Likes:    3097
 * Dislikes: 215
 * Total Accepted:    392.7K
 * Total Submissions: 649.9K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Note: 
 * 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * It's guaranteed that the answer is unique, in other words the set of the top
 * k frequent elements is unique.
 * You can return the answer in any order.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    struct cmp {
        bool operator() (pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        }
    };
    

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto n : nums) {
            m[n]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        for (auto i : m) {
            q.push(i);
        }
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(q.top().first);
            q.pop();
        }
        return res;
    }
};
// @lc code=end

