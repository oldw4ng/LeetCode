int baser,basec;
class Solution {
public:
    
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        basec = c0;
        baser = r0;
        vector<vector<int>> v;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                v.push_back({i, j});
            }
        }
        sort(v.begin(), v.end(), cmp);
        return v;
    }
    
    static bool cmp (vector<int>& lv, vector<int>& rv) {
        return (abs(lv[0] - baser) + abs(lv[1] - basec)) < (abs(rv[0] - baser) + abs(rv[1] - basec));
    }
};