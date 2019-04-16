class Solution {
public:
//很奇怪，这个题n^3也过了
    int longestArithSeqLength(vector<int>& A) {
        int res = 0;
        auto size = A.size();
        for (auto i = 0; i < size; ++i) {
            for (auto j = i + 1; j < size; ++j) {
                int d = A[j] - A[i];
                int next = A[j] + d;
                int count = 2;
                for (auto k = j + 1; k < size; ++k) {
                    if (A[k] == next) {
                        next += d;
                        count++;
                    }
                }
                res = max(res, count);
            }
        }
        return res;
    }
    
    
//附一个大佬的答案
//https://leetcode.com/problems/longest-arithmetic-sequence/discuss/274611/JavaC%2B%2BPython-DP
    int longestArithSeqLength(vector<int>& A) {
        unordered_map<int, unordered_map<int, int>> dp;
        int res = 2;
        for (int i = 0; i < A.size(); ++i)
            for (int j = i + 1; j < A.size(); ++j)  {
                int a = A[i], b = A[j];
                dp[b - a][j] = max(dp[b - a][j], dp[b - a][i] + 1);
                res = max(res, dp[b - a][j] + 1);
            }
        return res;
    }
    
};



