/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (41.06%)
 * Likes:    1436
 * Dislikes: 191
 * Total Accepted:    430.7K
 * Total Submissions: 1M
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5,6], 5
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,3,5,6], 2
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,3,5,6], 7
 * Output: 4
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [1,3,5,6], 0
 * Output: 0
 * 
 * 
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ret = 0;
        int lo = 0, hi = (int)nums.size() - 1;
        stack<pair<int, int>> s;
        s.push(make_pair(lo, hi));
        while (!s.empty()) {
            lo = s.top().first;
            hi = s.top().second;
            s.pop();
            if (lo > hi) {
                return lo;
            }
            int mid = (lo + hi) / 2;
            if (target == nums[mid]) {
                return mid;
            }
            if (target < nums[mid]) {
                s.push(make_pair(lo, mid - 1));
            } else {
                s.push(make_pair(mid + 1, hi));
            }
        }
        return ret;
    }
};

