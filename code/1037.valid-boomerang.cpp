/*
 * @lc app=leetcode id=1037 lang=cpp
 *
 * [1037] Valid Boomerang
 *
 * https://leetcode.com/problems/valid-boomerang/description/
 *
 * algorithms
 * Easy (37.58%)
 * Likes:    37
 * Dislikes: 128
 * Total Accepted:    8.7K
 * Total Submissions: 23.2K
 * Testcase Example:  '[[1,1],[2,3],[3,2]]'
 *
 * A boomerang is a set of 3 points that are all distinct and not in a straight
 * line.
 * 
 * Given a list of three points in the plane, return whether these points are a
 * boomerang.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,1],[2,3],[3,2]]
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,1],[2,2],[3,3]]
 * Output: false
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * points.length == 3
 * points[i].length == 2
 * 0 <= points[i][j] <= 100
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        if ((points[0][0] == points[1][0] && points[0][1] == points[1][1]) || (points[2][0] == points[1][0] && points[2][1] == points[1][1]))
            return false;
        if (points[0][0] == points[1][0]) {
            return points[2][0] != points[0][0];
        }
        return !((((double)(points[2][1] - points[0][1]) / (points[2][0] - points[0][0])) * (points[1][0] - points[0][0])) == points[1][1] - points[0][1]);
    }
};

