/*
 * @lc app=leetcode id=920 lang=cpp
 *
 * [920] Number of Music Playlists
 *
 * https://leetcode.com/problems/number-of-music-playlists/description/
 *
 * algorithms
 * Hard (44.02%)
 * Likes:    218
 * Dislikes: 29
 * Total Accepted:    5.8K
 * Total Submissions: 13.1K
 * Testcase Example:  '3\n3\n1'
 *
 * Your music player contains N different songs and she wants to listen to L
 * (not necessarily different) songs during your trip.  You create a playlist
 * so that:
 * 
 * 
 * Every song is played at least once
 * A song can only be played again only if K other songs have been played
 * 
 * 
 * Return the number of possible playlists.  As the answer can be very large,
 * return it modulo 10^9 + 7.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: N = 3, L = 3, K = 1
 * Output: 6
 * Explanation: There are 6 possible playlists. [1, 2, 3], [1, 3, 2], [2, 1,
 * 3], [2, 3, 1], [3, 1, 2], [3, 2, 1].
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: N = 2, L = 3, K = 0
 * Output: 6
 * Explanation: There are 6 possible playlists. [1, 1, 2], [1, 2, 1], [2, 1,
 * 1], [2, 2, 1], [2, 1, 2], [1, 2, 2]
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: N = 2, L = 3, K = 1
 * Output: 2
 * Explanation: There are 2 possible playlists. [1, 2, 1], [2, 1, 2]
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= K < N <= L <= 100
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        int mod = 1e9 + 7;
        long long dp[101][101];
        dp[1][1] = 1;
        for (int i = 2; i <= 100; i++) {
            dp[i][i] = (dp[i - 1][i - 1] * i) % mod;
        }
        for (int n = 1; n <= N; ++n) {
            for (int l = n + 1; l <= L; ++l) {
                dp[n][l] = ((dp[n][l - 1] * max(0, n - K)) % mod + (dp[n - 1][l - 1] * n) % mod) % mod;
            }
        }
        return dp[N][L];
    }
};

