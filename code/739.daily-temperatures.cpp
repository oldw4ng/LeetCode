/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> ret(size);
        stack<int> s;
        s.push(0);
        for (int i = 1; i < size; ) {
            if (!s.empty() && temperatures[s.top()] < temperatures[i]) {
                ret[s.top()] = i - s.top();
                s.pop();
                continue;
            }
            s.push(i);
            ++i;
        }
        return ret;
    }
};
// @lc code=end

