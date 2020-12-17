/*
 * @lc app=leetcode id=321 lang=cpp
 *
 * [321] Create Maximum Number
 *
 * https://leetcode.com/problems/create-maximum-number/description/
 *
 * algorithms
 * Hard (27.33%)
 * Likes:    826
 * Dislikes: 257
 * Total Accepted:    41.5K
 * Total Submissions: 151.8K
 * Testcase Example:  '[3,4,6,5]\n[9,1,2,5,8,3]\n5'
 *
 * Given two arrays of length m and n with digits 0-9 representing two numbers.
 * Create the maximum number of length k <= m + n from digits of the two. The
 * relative order of the digits from the same array must be preserved. Return
 * an array of the k digits.
 * 
 * Note: You should try to optimize your time and space complexity.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * nums1 = [3, 4, 6, 5]
 * nums2 = [9, 1, 2, 5, 8, 3]
 * k = 5
 * Output:
 * [9, 8, 6, 5, 3]
 * 
 * Example 2:
 * 
 * 
 * Input:
 * nums1 = [6, 7]
 * nums2 = [6, 0, 4]
 * k = 5
 * Output:
 * [6, 7, 6, 0, 4]
 * 
 * Example 3:
 * 
 * 
 * Input:
 * nums1 = [3, 9]
 * nums2 = [8, 9]
 * k = 3
 * Output:
 * [9, 8, 9]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> maxKSequence(vector<int>& nums, int n) {
        vector<int> stack(n, 0);
        int top = -1;
        int size = nums.size();
        int remain = size - n;
        for (auto num: nums) {
            while (top >= 0 && remain > 0 && stack[top] < num) {
                top--;
                remain--;
            }
            if (top < n - 1)
                stack[++top] = num;
            else
                remain--;
        }
        return stack;
    }

    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        if (!size1) return nums2;
        if (!size2) return nums1;
        vector<int> merged(size1 + size2, 0);
        int i = 0, j = 0, k = 0;
        while (k < size1 + size2) {
            if (compare(nums1, i, nums2, j) > 0) {
                merged[k++] = nums1[i++];
            } else {
                merged[k++] = nums2[j++];
            }
        }
        return merged;
    }

    int compare(vector<int>& nums1, int i,  vector<int>& nums2, int j) {
        int size1 = nums1.size(), size2 = nums2.size();
        while (i < size1 && j < size2) {
            int diff = nums1[i++] - nums2[j++];
            if (diff != 0) return diff;
        }
        return (size1 - i) - (size2 - j);
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int start = max(0, k - (int)nums2.size());
        int end = min(k, (int)nums1.size());
        vector<int> maxSequence(k, 0);
        for (int i = start; i <= end ; ++i) {
            auto max1(maxKSequence(nums1, i));
            auto max2(maxKSequence(nums2, k - i));
            auto cur(merge(max1, max2));
            if (compare(cur, 0, maxSequence, 0) > 0)
                maxSequence.swap(cur);
        }
        return maxSequence;
    }
};
// @lc code=end

