class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        return max(func(A, L, M), func(A, M, L));
    }
    int func(vector<int>& A, int L, int M) {
        int res = 0;
        size_t i = 0, j = A.size() - 1;
        vector<int> maxsumL(A.size(), 0), maxsumR(A.size(), 0);
        int sum = 0;
        for (; i < L; i++) {
            sum += A[i];
        }
        int maxmax = sum;
        maxsumL[i - 1] = maxmax;
        while (i < A.size() - M) {
            sum = sum - A[i - L] + A[i];
            maxmax = max(sum, maxmax);
            maxsumL[i] = maxmax;
            i++;
        }
        sum = 0;
        for (; j >= A.size()- M; j--) {
            sum += A[j];
        }
        maxmax = sum;
        maxsumR[j + 1] = maxmax;
        while (j >= L) {
            sum = sum - A[j + M] + A[j];
            maxmax = max(sum, maxmax);
            maxsumR[j] = maxmax;
            j--;
        }
        for (i = L - 1; i < A.size() - M; i++) {
            res = max(res, maxsumL[i] + maxsumR[i + 1]);
        }
        return res;
    }
};