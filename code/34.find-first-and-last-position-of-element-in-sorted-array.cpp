/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (36.33%)
 * Likes:    3928
 * Dislikes: 161
 * Total Accepted:    546.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums is a non decreasing array.
 * -10^9 <= target <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        int lo = 0, hi = nums.size() - 1;
        int mid = (lo + hi) / 2;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (nums[mid] == target)
                break;
            if (nums[mid] > target)
                hi = mid - 1;
            else
                lo = mid + 1; 
        }
        if (lo > hi) {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }
        int i = mid;
        while (i >= 0 && nums[i] == target)
            i--;
        ret.push_back(i + 1);
        i = mid;
        while (i < nums.size() && nums[i] == target)
            i++;
        ret.push_back(i - 1);
        return ret;
    }
};
// @lc code=end

