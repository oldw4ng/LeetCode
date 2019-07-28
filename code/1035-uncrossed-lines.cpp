class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size() + 1);
        for (int j = 0; j <= B.size(); ++j)
            dp[0].push_back(0);
        for (int i = 1; i <= A.size(); i++) {
            dp[i].push_back(0);
            for (int j = 1; j <= B.size(); ++j) {
                dp[i].push_back(A[i - 1] == B[j - 1]? dp[i - 1][j - 1] + 1: max(dp[i - 1][j], dp[i][j - 1]));
            }
        }
        return dp[A.size()][B.size()];
    }
};