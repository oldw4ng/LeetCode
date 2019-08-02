/*
 * @lc app=leetcode id=1139 lang=cpp
 *
 * [1139] Largest 1-Bordered Square
 *
 * https://leetcode.com/problems/largest-1-bordered-square/description/
 *
 * algorithms
 * Medium (41.99%)
 * Likes:    41
 * Dislikes: 17
 * Total Accepted:    3.1K
 * Total Submissions: 7.4K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a 2D grid of 0s and 1s, return the number of elements in the largest
 * square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't
 * exist in the grid.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
 * Output: 9
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[1,1,0,0]]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= grid.length <= 100
 * 1 <= grid[0].length <= 100
 * grid[i][j] is 0 or 1
 * 
 */
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int ret = 0;
        size_t width = grid[0].size(), hight = grid.size();
        int hor[hight][width], ver[hight][width];
        for (int i = 0; i < hight; ++i) {
            for (int j = 0; j < width; ++j) {
                if (grid[i][j]) {
                    hor[i][j] = (j == 0)? 1: hor[i][j - 1] + 1;
                    ver[i][j] = (i == 0)? 1: ver[i - 1][j] + 1;
                } else {
                    hor[i][j] = 0;
                    ver[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < hight; ++i) {
            for (int j = 0; j < width; ++j) {
                int mmin = min(hor[i][j], ver[i][j]);
                while (mmin > ret) {
                    if (ver[i][j - mmin + 1] >= mmin &&
                        hor[i - mmin + 1][j] >= mmin) {
                        ret = mmin;
                    }
                    mmin--;
                }
            }
        }
        return ret * ret;
    }
};

