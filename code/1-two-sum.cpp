class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (!map.count(nums[i])) {
                map.insert(pair<int, int>(nums[i], i));
            }
            if (map.count(target - nums[i])) {
                int j = map[target - nums[i]];
                if (j < i) {
                    result.push_back(j);
                    result.push_back(i);
                    return result;
                }
            }
        }
        return result;
    }
};
