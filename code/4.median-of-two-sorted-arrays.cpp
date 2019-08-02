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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result = 0;
        int size1 = (int)nums1.size();
        int size2 = (int)nums2.size();
        int hasMid = !((size1 + size2) % 2) + 1;
        bool status = (hasMid == 2);
        int mid = (size1 + size2) / 2 - hasMid / 2;
        cout << mid <<endl;
        
        int i = 0, j = 0, k = 0;
        for (; i < size1 && j < size2; ) {
            if (k == mid) {
                if (*(nums1.begin() + i) < *(nums2.begin() + j)) {
                    result += *(nums1.begin() + i);
                }else {
                    result += *(nums2.begin() + j);
                }
                if (status) {
                    mid++;
//                    ++k;
                    status = !status;
                    continue;
                }
                return result / hasMid;
            }
            if (*(nums1.begin() + i) < *(nums2.begin() + j)) {
                ++i;
            }else {
                ++j;
            }
            ++k;
        }
        for (; i < size1; ) {
            if (k == mid) {
                result += *(nums1.begin() + i);
                if (status) {
                    mid++;
                    //++k;
                    status = !status;
                    continue;
                }
                return result / hasMid;
            }
            ++i;
            ++k;
        }
        for (; j < size2; ) {
            if (k == mid) {
                result += *(nums2.begin() + j);
                if (status) {
                    mid++;
                    //++k;
                    status = !status;
                    continue;
                }
                return result / hasMid;
            }
            ++j;
            ++k;
        }
        return result / hasMid;
    }
};

