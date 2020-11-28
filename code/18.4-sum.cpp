/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (34.21%)
 * Likes:    2587
 * Dislikes: 366
 * Total Accepted:    368.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Notice that the solution set must not contain duplicate quadruplets.
 * 
 * 
 * Example 1:
 * Input: nums = [1,0,-1,0,-2,2], target = 0
 * Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * Example 2:
 * Input: nums = [], target = 0
 * Output: []
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 200
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        if (nums.size() < 4)
            return ret;
        sort(nums.begin(), nums.end());
        auto size = nums.size();
        int a = 0, b = 1, c = 2, d = nums.size() - 1;
        while (a < size - 3) {
            b = a + 1;
            if (nums[a] + nums[a + 1] + nums[a + 2] + nums[a + 3] > target) break;
            while (b < size - 2) {
                c = b + 1;
                d = nums.size() - 1;
                if (nums[a] + nums[b] + nums[c] + nums[c + 1] > target) break;
                while (c < d) {
                    auto sum = nums[a] + nums[b] + nums[c] + nums[d];
                    if (sum == target) {
                        ret.push_back({nums[a], nums[b], nums[c], nums[d]});
                    }
                    if (sum >= target) {
                        do {
                            d--;
                        } while (c < d && nums[d] == nums[d + 1]);
                    }
                    if (sum <= target) {
                        do {
                            c++;
                        } while (c < d && nums[c] == nums[c - 1]);
                    }
                }
                do {
                    b++;
                } while (b < size - 2 && nums[b] == nums[b - 1]);
            }
            do {
                a++;
            } while (a < size - 3 && nums[a] == nums[a - 1]);
        }
        return ret;
    }
};
// @lc code=end

