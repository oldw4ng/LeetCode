/*
 * @lc app=leetcode id=1010 lang=cpp
 *
 * [1010] Pairs of Songs With Total Durations Divisible by 60
 *
 * https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/description/
 *
 * algorithms
 * Easy (45.73%)
 * Likes:    184
 * Dislikes: 15
 * Total Accepted:    14.4K
 * Total Submissions: 31.6K
 * Testcase Example:  '[30,20,150,100,40]'
 *
 * In a list of songs, the i-th song has a duration of time[i] seconds. 
 * 
 * Return the number of pairs of songs for which their total duration in
 * seconds is divisible by 60.  Formally, we want the number of indices i < j
 * with (time[i] + time[j]) % 60 == 0.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [30,20,150,100,40]
 * Output: 3
 * Explanation: Three pairs have a total duration divisible by 60:
 * (time[0] = 30, time[2] = 150): total duration 180
 * (time[1] = 20, time[3] = 100): total duration 120
 * (time[1] = 20, time[4] = 40): total duration 60
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [60,60,60]
 * Output: 3
 * Explanation: All three pairs have a total duration of 120, which is
 * divisible by 60.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= time.length <= 60000
 * 1 <= time[i] <= 500
 * 
 */
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ret = 0;
        int times[60] = {0};
        for (auto item : time) {
            times[item % 60]++;
        }
        for (int i = 1; i < 30; ++i) {
            ret += times[i] * times[60 - i];
        }
        if (times[0]) {
            ret += times[0] * (times[0] - 1) / 2;
        }
        if (times[30]) {
            ret += times[30] * (times[30] - 1) / 2;
        }
        return ret;
    }
};

