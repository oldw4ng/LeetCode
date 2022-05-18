/*
 * @lc app=leetcode id=1396 lang=cpp
 *
 * [1396] Design Underground System
 */

// @lc code=start

class UndergroundSystem {
    unordered_map<int, pair<string, int>> pending;
    unordered_map<string, pair<int, int>> history;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        pending[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        auto travel = pending[id];
        string route = travel.first + "_" + stationName;
        history[route].first += t - travel.second;
        history[route].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto route = history[startStation + "_" + endStation];
        return (double) route.first / route.second; 
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
// @lc code=end

