/*
 * @lc app=leetcode id=1128 lang=cpp
 *
 * [1128] Number of Equivalent Domino Pairs
 *
 * https://leetcode.com/problems/number-of-equivalent-domino-pairs/description/
 *
 * algorithms
 * Easy (43.20%)
 * Likes:    53
 * Dislikes: 21
 * Total Accepted:    7.2K
 * Total Submissions: 16.5K
 * Testcase Example:  '[[1,2],[2,1],[3,4],[5,6]]'
 *
 * Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j]
 * = [c, d] if and only if either (a==c and b==d), or (a==d and b==c) - that
 * is, one domino can be rotated to be equal to another domino.
 * 
 * Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length,
 * and dominoes[i] is equivalent to dominoes[j].
 * 
 * 
 * Example 1:
 * Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
 * Output: 1
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= dominoes.length <= 40000
 * 1 <= dominoes[i][j] <= 9
 * 
 */
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ret = 0;
        map<pair<int, int>, int> m;
        for (auto item : dominoes) {
            pair<int, int> p, pr;
            p.first = item[0];
            p.second = item[1];
            pr.first = item[1];
            pr.second = item[0];
            if (!(m.count(p) || m.count(pr))) {
                m[p] = 1;
            } else {
                if (m.count(p)) {
                    ret += m[p];
                    m[p]++;
                    
                } else {
                    ret += m[pr];
                    m[pr]++;
                }
            }
        }
        return ret;
    }
};

