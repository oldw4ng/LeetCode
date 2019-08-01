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