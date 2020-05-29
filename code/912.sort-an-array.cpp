/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 *
 * https://leetcode.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (63.60%)
 * Likes:    129
 * Dislikes: 124
 * Total Accepted:    22.1K
 * Total Submissions: 35K
 * Testcase Example:  '[5,2,3,1]'
 *
 * Given an array of integers nums, sort the array in ascending order.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [5,2,3,1]
 * Output: [1,2,3,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [5,1,1,2,0,0]
 * Output: [0,0,1,1,2,5]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 10000
 * -50000 <= A[i] <= 50000
 * 
 * 
 */
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        q_sort(nums, 0, nums.size() - 1);
        return nums;
    }
    
    void q_sort(vector<int>& nums, int lo, int hi) {
        if(lo >= hi)
            return;
        int i = lo, j = hi, flag = nums[lo];
        while(i < j) {
            while(i < j && nums[j] >= flag)
                j--;
            nums[i] = nums[j];
            while(i < j && nums[i] < flag)
                i++;
            nums[j] = nums[i];
        }
        nums[i] = flag;
        q_sort(nums, lo, i - 1);
        q_sort(nums, i + 1, hi);
    }
};

