/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 *
 * https://leetcode.com/problems/task-scheduler/description/
 *
 * algorithms
 * Medium (45.96%)
 * Likes:    1797
 * Dislikes: 314
 * Total Accepted:    95.4K
 * Total Submissions: 207.6K
 * Testcase Example:  '["A","A","A","B","B","B"]\n2'
 *
 * Given a char array representing tasks CPU need to do. It contains capital
 * letters A to Z where different letters represent different tasks. Tasks
 * could be done without original order. Each task could be done in one
 * interval. For each interval, CPU could finish one task or just be idle.
 * 
 * However, there is a non-negative cooling interval n that means between two
 * same tasks, there must be at least n intervals that CPU are doing different
 * tasks or just be idle.
 * 
 * You need to return the least number of intervals the CPU will take to finish
 * all the given tasks.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 * Output: 8
 * Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of tasks is in the range [1, 10000].
 * The integer n is in the range [0, 100].
 * 
 * 
 */
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> taskn;
        for (auto item : tasks) {
            taskn[item]++;
        }
        int maxTask = 0;
        for (auto item : taskn) {
            maxTask = item.second > maxTask? item.second: maxTask;
        }
        int cntMax = 0;
        for (auto item : taskn) {
            cntMax += item.second == maxTask;
        }
        return max((int)tasks.size(), (maxTask - 1) * (n  + 1) + cntMax);
    }
};

