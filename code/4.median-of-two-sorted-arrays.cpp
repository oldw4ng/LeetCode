/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (26.89%)
 * Likes:    4698
 * Dislikes: 663
 * Total Accepted:    474.1K
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
class Solution {
public:
    double getKthNum(vector<int>& nums1, vector<int>& nums2, int k) {
        int l1 = 0, l2 = 0;
        int size1 = nums1.size(), size2 = nums2.size();
        double ret = 0;
        while (1) {
            if (l1 == size1) {
                return nums2[l2 + k - 1];
            }
            if (l2 == size2) {
                return nums1[l1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[l1], nums2[l2]);
            }
            int half = k / 2;
            int newl1 = min(l1 + half, size1) - 1;
            int newl2 = min(l2 + half, size2) - 1;
            if (nums1[newl1] <= nums2[newl2]) {
                k -= (newl1 - l1 + 1);
                l1 = newl1 + 1;
            } else {
                k -= (newl2 - l2 + 1);
                l2 = newl2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int k = (nums1.size() + nums2.size() + 1) / 2;
        if ((nums1.size() + nums2.size()) % 2) {
            return getKthNum(nums1, nums2, k);
        } else {
            return (getKthNum(nums1, nums2, k) + getKthNum(nums1, nums2, k + 1)) / 2.0;
        }
    }
};
