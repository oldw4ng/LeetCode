/*
 * @lc app=leetcode id=1131 lang=cpp
 *
 * [1131] Maximum of Absolute Value Expression
 *
 * https://leetcode.com/problems/maximum-of-absolute-value-expression/description/
 *
 * algorithms
 * Medium (50.36%)
 * Likes:    40
 * Dislikes: 51
 * Total Accepted:    2.5K
 * Total Submissions: 5K
 * Testcase Example:  '[1,2,3,4]\r\n[-1,4,5,6]\r'
 *
 * Given two arrays of integers with equal lengths, return the maximum value
 * of:
 * 
 * |arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|
 * 
 * where the maximum is taken over all 0 <= i, j < arr1.length.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
 * Output: 13
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
 * Output: 20
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= arr1.length == arr2.length <= 40000
 * -10^6 <= arr1[i], arr2[i] <= 10^6
 * 
 */
class Solution {
public:
    int getMax(vector<int> &v) {
        int mmax = INT_MIN, mmin = INT_MAX;
        for (auto item : v) {
            mmax = max(mmax, item);
            mmin = min(mmin, item);
        }
        return mmax - mmin;
    }
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        size_t size = arr1.size();
        vector<int> v1(size,0), v2(size,0), v3(size,0), v4(size,0);
        for (int  i = 0; i < size; ++i) {
            v1[i] = arr1[i] + arr2[i] + i;
            v2[i] = arr1[i] + arr2[i] - i;
            v3[i] = arr1[i] - arr2[i] + i;
            v4[i] = arr1[i] - arr2[i] - i;
        }
        return max(max(getMax(v1), getMax(v2)), max(getMax(v3), getMax(v4)));
    }
};

