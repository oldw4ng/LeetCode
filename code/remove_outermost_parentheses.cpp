class Solution {
public:
    string removeOuterParentheses(string S) {
        decltype(S.size()) lcnt = 0;
        string res;
        string sub;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '(') {
                lcnt++;
            } else
                lcnt--;
            sub += S[i];
            if (!lcnt) {
                res += sub.substr(1, sub.size() - 2);
                sub = "";
            }
        }
        return res;
    }
};