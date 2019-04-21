class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int res = 0;
        size_t goA = costs.size() / 2, goB = costs.size() / 2;
        sort(costs.begin(), costs.end(), cmp);
        size_t i = 0;
        while (goA && goB && i < costs.size()) {
            if (costs[i][0] < costs[i][1]) {
                res += costs[i][0];
                goA--;
            } else {
                res += costs[i][1];
                goB--;
            }
            i++;
        }
        while (goA && i < costs.size()) {
            res += costs[i][0];
            goA--;
            i++;
        }
        while (goB && i < costs.size()) {
            res += costs[i][1];
            goB--;
            i++;
        }
        
        return res;
    }
    static bool cmp (vector<int>& lv, vector<int>& rv) {
        if (abs(lv[0] - lv[1]) == abs(rv[0] - rv[1])) {
            return min(lv[0], lv[1]) > min(rv[0], rv[1]);
        }
        return abs(lv[0] - lv[1]) > abs(rv[0] - rv[1]);
    }

};