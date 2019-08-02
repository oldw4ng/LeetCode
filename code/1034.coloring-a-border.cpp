/*
 * @lc app=leetcode id=1034 lang=cpp
 *
 * [1034] Coloring A Border
 *
 * https://leetcode.com/problems/coloring-a-border/description/
 *
 * algorithms
 * Medium (42.76%)
 * Likes:    50
 * Dislikes: 126
 * Total Accepted:    5.2K
 * Total Submissions: 12.1K
 * Testcase Example:  '[[1,1],[1,2]]\n0\n0\n3'
 *
 * Given a 2-dimensional grid of integers, each value in the grid represents
 * the color of the grid square at that location.
 * 
 * Two squares belong to the same connected component if and only if they have
 * the same color and are next to each other in any of the 4 directions.
 * 
 * The border of a connected component is all the squares in the connected
 * component that are either 4-directionally adjacent to a square not in the
 * component, or on the boundary of the grid (the first or last row or
 * column).
 * 
 * Given a square at location (r0, c0) in the grid and a color, color the
 * border of the connected component of that square with the given color, and
 * return the final grid.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[1,1],[1,2]], r0 = 0, c0 = 0, color = 3
 * Output: [[3, 3], [3, 2]]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[1,2,2],[2,3,2]], r0 = 0, c0 = 1, color = 3
 * Output: [[1, 3, 3], [2, 3, 3]]
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [[1,1,1],[1,1,1],[1,1,1]], r0 = 1, c0 = 1, color = 2
 * Output: [[2, 2, 2], [2, 1, 2], [2, 2, 2]]
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= grid.length <= 50
 * 1 <= grid[0].length <= 50
 * 1 <= grid[i][j] <= 1000
 * 0 <= r0 < grid.length
 * 0 <= c0 < grid[0].length
 * 1 <= color <= 1000
 * 
 */
class Solution {
    vector<vector<int>> _grid;
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        _grid = grid;
        int c = grid[r0][c0];
        dfs(r0, c0, grid[r0][c0]);
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (_grid[i][j] == 0 && (isValid(i - 1, j) || isValid(i + 1, j) || isValid(i, j - 1) || isValid(i, j + 1))) {
                    grid[i][j] = color;
                } else if (_grid[i][j] == 0)
                    grid[i][j] = c;
            }
        }
        return grid;
    }
    
    bool isValid (int x, int y) {
        return x < 0 || x >= _grid.size() || y < 0 || y >= _grid[0].size() || _grid[x][y];
    }
    
    void dfs(int x, int y, int color) {
        if (x < 0 || x >= _grid.size() || y < 0 || y >= _grid[0].size() || _grid[x][y] != color) {
            return;
        }
        _grid[x][y] = 0;
        dfs(x - 1, y, color);
        dfs(x + 1, y, color);
        dfs(x, y - 1, color);
        dfs(x, y + 1, color);
    }
};

