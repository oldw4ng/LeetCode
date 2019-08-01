class Solution {
public:
    string addBinary(string a, string b) {
        size_t aSize = a.size(), bSize = b.size();
        string ret = "";
        int add = 0;
        int i, j;
        for (i = aSize - 1, j = bSize - 1; i >= 0 && j >= 0; --i, --j) {
            char thisC = (a[i] + b[j] - '0' - '0' + add) % 2 + '0';
            add = (a[i] + b[j] - '0' - '0' + add) / 2;
            ret = thisC + ret;
        }
        for (; i >= 0; --i) {
            char thisC = (a[i] - '0' + add) % 2 + '0';
            add = (a[i] - '0' + add) / 2;
            ret = thisC + ret;
        }
        for (; j >= 0; --j) {
            char thisC = (b[j] - '0' + add) % 2 + '0';
            add = (b[j] - '0' + add) / 2;
            ret = thisC + ret;
        }
        if (add) {
            ret = "1" + ret;
        }
        return ret;
    }
};