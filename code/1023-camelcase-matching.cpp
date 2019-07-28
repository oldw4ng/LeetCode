class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for (auto item : queries) {
            res.push_back(judge(item, pattern));
        }
        return res;
    }
    
    bool judge(string s, string p) {
        string str;
        int i = 0, j = 0;
        for (; i < s.size() && j < p.size(); ) {
            if (s[i] == p[j]) {
                i++;
                j++;
            } else {
                str += s[i++];
            }
        }
        while (i < s.size()) {
            str += s[i++];
        }
        if (j < p.size()) {
            return false;
        }
        for (i = 0; i < str.size(); ++i) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                return false;
            }
        }
        return true;
    }
};
