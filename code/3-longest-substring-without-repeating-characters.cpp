class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        queue<char> tempLS;
        map<char, int> map;
        for (int i = 0; i < s.size(); i++) {
            if (!map.count(s[i])) {
                map.insert(pair<char, int>(s[i], i));
                tempLS.push(s[i]);
            }else {
                result = result > tempLS.size()? result: tempLS.size();
                while (!tempLS.empty()) {
                    if (tempLS.front() != s[i]) {
                        map.erase(tempLS.front());
                        tempLS.pop();
                    }else {
                        map.erase(tempLS.front());
                        tempLS.pop();
                        break;
                    }
                }
                map.insert(pair<char, int>(s[i], i));
                tempLS.push(s[i]);
            }
        }
        result = result >= tempLS.size()? result: tempLS.size();
        return result;
    }
};