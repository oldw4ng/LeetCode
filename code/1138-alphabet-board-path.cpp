class Solution {
public:
    string alphabetBoardPath(string target) {
        string move[26][26];
        for(size_t i = 0; i < 26; ++i) {
            for(size_t j = 0; j < 26; ++j) {
                string str = "";
                int x1 = i % 5, y1 = i / 5, x2 = j % 5, y2 = j / 5;
                if(i == 25) {
                    str += "U";
                    x1 = 0; y1 = 4;
                }
                if(x2 > x1) {
                    for (int t = x1; t < x2; ++t)
                        str += "R";
                } else {
                    for (int t = x1; t > x2; --t)
                        str += "L";
                }
                if(y2 > y1) {
                    for (int t = y1; t < y2; ++t)
                        str += "D";
                } else {
                    for (int t = y1; t > y2; --t)
                        str += "U";
                }
                str += "!";
                move[i][j] = str;
            }
        }
        move[25][25] = "!";
        char last = 'a';
        string ret = "";
        for(int i = 0; i < target.size(); ++i) {
            ret += move[last - 'a'][target[i] - 'a'];
            last = target[i];
        }
        return ret;
    }
};