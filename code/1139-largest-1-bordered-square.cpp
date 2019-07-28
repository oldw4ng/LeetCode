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