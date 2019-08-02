/*
 * @lc app=leetcode id=1027 lang=cpp
 *
 * [1027] Longest Arithmetic Sequence
 *
 * https://leetcode.com/problems/longest-arithmetic-sequence/description/
 *
 * algorithms
 * Medium (49.06%)
 * Likes:    207
 * Dislikes: 12
 * Total Accepted:    10.7K
 * Total Submissions: 21.9K
 * Testcase Example:  '[3,6,9,12]'
 *
 * Given an array A of integers, return the length of the longest arithmetic
 * subsequence in A.
 * 
 * Recall that a subsequence of A is a list A[i_1], A[i_2], ..., A[i_k] with 0
 * <= i_1 < i_2 < ... < i_k <= A.length - 1, and that a sequence B is
 * arithmetic if B[i+1] - B[i] are all the same value (for 0 <= i < B.length -
 * 1).
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [3,6,9,12]
 * Output: 4
 * Explanation: 
 * The whole array is an arithmetic sequence with steps of length = 3.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [9,4,7,2,10]
 * Output: 3
 * Explanation: 
 * The longest arithmetic subsequence is [4,7,10].
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [20,1,15,3,10,5,8]
 * Output: 4
 * Explanation: 
 * The longest arithmetic subsequence is [20,15,10,5].
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 2 <= A.length <= 2000
 * 0 <= A[i] <= 10000
 * 
 * 
 */
class Solution {
public:
//???????n^3???
    int longestArithSeqLength(vector<int>& A) {
        int ret = 0;
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
                ret = max(ret, count);
            }
        }
        return ret;
    }
    
    
//????????
//https://leetcode.com/problems/longest-arithmetic-sequence/discuss/274611/JavaC%2B%2BPython-DP
    int longestArithSeqLength(vector<int>& A) {
        unordered_map<int, unordered_map<int, int>> dp;
        int ret = 2;
        for (int i = 0; i < A.size(); ++i)
            for (int j = i + 1; j < A.size(); ++j)  {
                int a = A[i], b = A[j];
                dp[b - a][j] = max(dp[b - a][j], dp[b - a][i] + 1);
                ret = max(ret, dp[b - a][j] + 1);
            }
        return ret;
    }
    
};

