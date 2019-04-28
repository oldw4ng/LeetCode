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