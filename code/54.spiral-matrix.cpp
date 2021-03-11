/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (35.16%)
 * Likes:    3213
 * Dislikes: 626
 * Total Accepted:    439.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 10
 * -100 <= matrix[i][j] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if (matrix.size() == 0)
            return ret;
        int dst = 0;    // 0 right 1 down 2 left 3 up
        int l = 0, r = matrix[0].size() - 1, top = 0, bot = matrix.size() - 1;
        while (l <= r && top <= bot) {
            if (dst == 0) {
                for (int i = l; i <= r; ++i) {
                    ret.push_back(matrix[top][i]);
                }
                top++;
            } else if (dst == 1) {
                for (int i = top; i <= bot; ++i) {
                    ret.push_back(matrix[i][r]);
                }
                r--;
            } else if (dst == 2) {
                for (int i = r; i >= l; --i) {
                    ret.push_back(matrix[bot][i]);
                }
                bot--;
            } else if (dst == 3) {
                for (int i = bot; i >= top; --i) {
                    ret.push_back(matrix[i][l]);
                }
                l++;
            }
            dst = (dst + 1) % 4;
        }
        return ret;
    }
};
// @lc code=end

