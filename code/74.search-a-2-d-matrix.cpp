/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (37.05%)
 * Likes:    2483
 * Dislikes: 174
 * Total Accepted:    385K
 * Total Submissions: 1M
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 13
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: matrix = [], target = 0
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 0 <= m, n <= 100
 * -10^4 <= matrix[i][j], target <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int row = 0;
        for (; row < matrix.size() - 1; ++row) {
            if (target >= matrix[row][0] && target < matrix[row + 1][0]) {
                break;
            }
        }
        return binarySearch(0, matrix[0].size() - 1, matrix[row], target);
    }

    bool binarySearch(int lo, int hi, vector<int>& nums, int target) {
        if (lo > hi)
            return false;
        int mid = (lo + hi) / 2;
        if (nums[mid] == target)
            return true;
        if (nums[mid] > target)
            return binarySearch(lo, mid - 1, nums, target);
        return binarySearch(mid + 1, hi, nums, target);
    }
};
// @lc code=end

