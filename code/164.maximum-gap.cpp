/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 *
 * https://leetcode.com/problems/maximum-gap/description/
 *
 * algorithms
 * Hard (36.25%)
 * Likes:    996
 * Dislikes: 196
 * Total Accepted:    95.4K
 * Total Submissions: 262.4K
 * Testcase Example:  '[3,6,9,1]'
 *
 * Given an unsorted array, find the maximum difference between the successive
 * elements in its sorted form.
 * 
 * Return 0 if the array contains less than 2 elements.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,6,9,1]
 * Output: 3
 * Explanation: The sorted form of the array is [1,3,6,9], either
 * (3,6) or (6,9) has the maximum difference 3.
 * 
 * Example 2:
 * 
 * 
 * Input: [10]
 * Output: 0
 * Explanation: The array contains less than 2 elements, therefore return 0.
 * 
 * Note:
 * 
 * 
 * You may assume all elements in the array are non-negative integers and fit
 * in the 32-bit signed integer range.
 * Try to solve it in linear time/space.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        int minN = *min_element(nums.begin(), nums.end());
        int maxN = *max_element(nums.begin(), nums.end());
        int d = max(1, (int)((maxN - minN) / (nums.size() - 1)));
        int bucketSize = (maxN - minN) / d + 1;
        vector<pair<int, int>> v(bucketSize, {-1, -1});
        for (int i = 0; i < nums.size(); ++i) {
            int pos = (nums[i] - minN) / d;
            if (v[pos].first == -1) {
                v[pos].first = nums[i];
                v[pos].second = nums[i];
            } else {
                v[pos].first = min(v[pos].first, nums[i]);
                v[pos].second = max(v[pos].second, nums[i]);
            }
        }
        int ret = 0;
        int pre = -1;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i].first == -1) continue;
            if (pre != -1)
                ret = max(ret, v[i].first - v[pre].second);
            pre = i;
        }
        return ret;
    }
};
// @lc code=end

