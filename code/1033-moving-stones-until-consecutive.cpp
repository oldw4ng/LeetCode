class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> res(2);
        if (a > b) {
            swap(a, b);
        }
        if (b > c) {
            swap(b, c);
        }
        if (a > b) {
            swap(a, b);
        }
        res[1] = c - a - 2;
        if (c - b == 2 || b - a == 2) {
            res[0] = 1;
        } else if ((c - b == 1 && b - a > 1) || (b - a == 1 && c - b > 1)) {
            res[0] = 1;
        } else if (c -b == 1 && b - a == 1) {
            res[0] = 0;
        } else
            res[0] = 2;
        return res;
    }
};