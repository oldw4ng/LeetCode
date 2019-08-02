/*
 * @lc app=leetcode id=1029 lang=cpp
 *
 * [1029] Two City Scheduling
 *
 * https://leetcode.com/problems/two-city-scheduling/description/
 *
 * algorithms
 * Easy (54.27%)
 * Likes:    263
 * Dislikes: 31
 * Total Accepted:    11.6K
 * Total Submissions: 21.4K
 * Testcase Example:  '[[10,20],[30,200],[400,50],[30,20]]'
 *
 * There are 2N people a company is planning to interview. The cost of flying
 * the i-th person to city A is costs[i][0], and the cost of flying the i-th
 * person to city B is costs[i][1].
 * 
 * Return the minimum cost to fly every person to a city such that exactly N
 * people arrive in each city.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[10,20],[30,200],[400,50],[30,20]]
 * Output: 110
 * Explanation: 
 * The first person goes to city A for a cost of 10.
 * The second person goes to city A for a cost of 30.
 * The third person goes to city B for a cost of 50.
 * The fourth person goes to city B for a cost of 20.
 * 
 * The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people
 * interviewing in each city.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= costs.length <= 100
 * It is guaranteed that costs.length is even.
 * 1 <= costs[i][0], costs[i][1] <= 1000
 * 
 */
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ret = 0;
        size_t goA = costs.size() / 2, goB = costs.size() / 2;
        sort(costs.begin(), costs.end(), cmp);
        size_t i = 0;
        while (goA && goB && i < costs.size()) {
            if (costs[i][0] < costs[i][1]) {
                ret += costs[i][0];
                goA--;
            } else {
                ret += costs[i][1];
                goB--;
            }
            i++;
        }
        while (goA && i < costs.size()) {
            ret += costs[i][0];
            goA--;
            i++;
        }
        while (goB && i < costs.size()) {
            ret += costs[i][1];
            goB--;
            i++;
        }
        
        return ret;
    }
    static bool cmp (vector<int>& lv, vector<int>& rv) {
        if (abs(lv[0] - lv[1]) == abs(rv[0] - rv[1])) {
            return min(lv[0], lv[1]) > min(rv[0], rv[1]);
        }
        return abs(lv[0] - lv[1]) > abs(rv[0] - rv[1]);
    }

};

