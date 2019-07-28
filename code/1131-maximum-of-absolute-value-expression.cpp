class Solution {
public:
    int getMax(vector<int> &v) {
        int mmax = INT_MIN, mmin = INT_MAX;
        for (auto item : v) {
            mmax = max(mmax, item);
            mmin = min(mmin, item);
        }
        return mmax - mmin;
    }
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        size_t size = arr1.size();
        vector<int> v1(size,0), v2(size,0), v3(size,0), v4(size,0);
        for (int  i = 0; i < size; ++i) {
            v1[i] = arr1[i] + arr2[i] + i;
            v2[i] = arr1[i] + arr2[i] - i;
            v3[i] = arr1[i] - arr2[i] + i;
            v4[i] = arr1[i] - arr2[i] - i;
        }
        return max(max(getMax(v1), getMax(v2)), max(getMax(v3), getMax(v4)));
    }
};