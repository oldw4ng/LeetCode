/*
 * @lc app=leetcode id=861 lang=cpp
 *
 * [861] Score After Flipping Matrix
 *
 * https://leetcode.com/problems/score-after-flipping-matrix/description/
 *
 * algorithms
 * Medium (73.16%)
 * Likes:    572
 * Dislikes: 130
 * Total Accepted:    23.9K
 * Total Submissions: 32.7K
 * Testcase Example:  '[[0,0,1,1],[1,0,1,0],[1,1,0,0]]'
 *
 * We have a two dimensional matrix A where each value is 0 or 1.
 * 
 * A move consists of choosing any row or column, and toggling each value in
 * that row or column: changing all 0s to 1s, and all 1s to 0s.
 * 
 * After making any number of moves, every row of this matrix is interpreted as
 * a binary number, and the score of the matrix is the sum of these numbers.
 * 
 * Return the highest possible score.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
 * Output: 39
 * Explanation:
 * Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
 * 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 20
 * 1 <= A[0].length <= 20
 * A[i][j] is 0 or 1.
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int lines = A.size(), cols = A[0].size();
        for (int i = 0; i < lines; ++i) {
            if (!A[i][0]) {
                for (int j = 0; j < A[i].size(); ++j) {
                    A[i][j] = !A[i][j];
                }
            }
        }
        for (int i = 1; i < cols; ++i) {
            int n[2] = {0};
            for (int j = 0; j < lines; ++j) {
                n[A[j][i]]++;
            }
            if (n[0] > n[1]) {
                for (int j = 0; j < lines; ++j) {
                    A[j][i] = !A[j][i];
                }
            }
        }
        int ret = 0;
        for (int i = 0; i < lines; ++i) {
            for (int j = 0; j < cols; ++j) {
                ret += (A[i][j] << (cols - 1 - j));
            }
        }
        return ret;
    }
};
// @lc code=end

