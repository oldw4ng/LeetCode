/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 *
 * https://leetcode.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (33.59%)
 * Likes:    933
 * Dislikes: 143
 * Total Accepted:    213.3K
 * Total Submissions: 635.2K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 * 
 * 
 * 
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * 
 * Note: m and n will be at most 100.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * Output: 2
 * Explanation:
 * There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 * 
 * 
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        size_t m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<long>> v(m, vector<long>(n, 0));
        for (size_t i = 0; i < m && !obstacleGrid[i][0]; ++i) {
            v[i][0] = 1;
        }
        for (size_t i = 0; i < n && !obstacleGrid[0][i]; ++i) {
            v[0][i] = 1;
        }
        for (size_t i = 1; i < m; ++i) {
            for (size_t j = 1; j < n; ++j) {
                if (obstacleGrid[i][j]) {
                    v[i][j] = 0;
                } else
                    v[i][j] = v[i - 1][j] + v[i][j - 1];
            }
        }
        return v[m - 1][n - 1];
    }
};

