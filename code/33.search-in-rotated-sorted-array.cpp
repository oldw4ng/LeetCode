/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (target > nums[mid]) {
                if (target == nums[l]) {
                    return l;
                }
                if (target > nums[l]) {
                    if (nums[l] > nums[mid]) {
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                } else {
                    l = mid + 1;
                }
            } else {
                if (target == nums[l]) {
                    return l;
                }
                if (target < nums[l]) {
                    if (nums[l] > nums[mid]) {
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                } else {
                        r = mid - 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

