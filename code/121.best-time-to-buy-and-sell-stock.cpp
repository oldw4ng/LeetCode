class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest = INT_MAX;
        int ret = 0;
        for (auto price: prices) {
            ret = max(ret, price - lowest);
            lowest = min(lowest, price);
        }
        return ret;
    }
};