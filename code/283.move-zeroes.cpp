/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (54.78%)
 * Likes:    2200
 * Dislikes: 79
 * Total Accepted:    498.1K
 * Total Submissions: 909.3K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Note:
 * 
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        for (; i < nums.size(); i++) {
            if (nums[i] != 0)
                nums[j++] = nums[i];
        }
        for (; j < nums.size(); j++)
            nums[j] = 0;
    }
};

