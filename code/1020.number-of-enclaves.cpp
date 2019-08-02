/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 *
 * https://leetcode.com/problems/number-of-enclaves/description/
 *
 * algorithms
 * Medium (54.69%)
 * Likes:    98
 * Dislikes: 13
 * Total Accepted:    8.3K
 * Total Submissions: 15.2K
 * Testcase Example:  '[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]'
 *
 * Given a 2D array A, each cell is 0 (representing sea) or 1 (representing
 * land)
 * 
 * A move consists of walking from one land square 4-directionally to another
 * land square, or off the boundary of the grid.
 * 
 * Return the number of land squares in the grid for which we cannot walk off
 * the boundary of the grid in any number of moves.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
 * Output: 3
 * Explanation: 
 * There are three 1s that are enclosed by 0s, and one 1 that isn't enclosed
 * because its on the boundary.
 * 
 * Example 2:
 * 
 * 
 * Input: [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
 * Output: 0
 * Explanation: 
 * All 1s are either on the boundary or can reach the boundary.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 500
 * 1 <= A[i].length <= 500
 * 0 <= A[i][j] <= 1
 * All rows have the same size.
 * 
 */
class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        int num = 0;
        stack<pair<int, int>> s;
        int m = A.size(), n = A[0].size();
        for (int i = 0; i < m; ++i) {
            if (A[i][0]) {
                s.push({i, 0});
                A[i][0] = 0;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (A[0][i]) {
                s.push({0, i});
                A[0][i] = 0;
            }
        }
        for (int i = 0; i < m; ++i) {
            if (A[i][n - 1]) {
                s.push({i, n - 1});
                A[i][n - 1] = 0;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (A[m - 1][i]) {
                s.push({m - 1, i});
                A[m - 1][i] = 0;
            }
        }
        
        while (!s.empty()) {
            int x = s.top().first, y = s.top().second;
            if (x + 1 >= 0 && x + 1 < m && A[x + 1][y]) {
                s.push({x + 1, y});
                A[x + 1][y] = 0;
                continue;
            }
            if (x - 1 >= 0 && x - 1 < m && A[x - 1][y]) {
                s.push({x - 1, y});
                A[x - 1][y] = 0;
                continue;
            }
            if (y + 1 >= 0 && y + 1 < n && A[x][y + 1]) {
                s.push({x, y + 1});
                A[x][y + 1] = 0;
                continue;
            }
            if (y - 1 >= 0 && y - 1 < n && A[x][y - 1]) {
                s.push({x, y - 1});
                A[x][y - 1] = 0;
                continue;
            }
            s.pop();
        }
        
        for (auto &m : A) {
            for (auto &n : m) {
                if (n) {
                    num++;
                }
            }
        }
        return num;
    }
};

