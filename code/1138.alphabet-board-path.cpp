/*
 * @lc app=leetcode id=1138 lang=cpp
 *
 * [1138] Alphabet Board Path
 *
 * https://leetcode.com/problems/alphabet-board-path/description/
 *
 * algorithms
 * Medium (41.94%)
 * Likes:    38
 * Dislikes: 21
 * Total Accepted:    4.5K
 * Total Submissions: 10.7K
 * Testcase Example:  '"leet"'
 *
 * On an alphabet board, we start at position (0, 0), corresponding to
 * character board[0][0].
 * 
 * Here, board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"], as shown
 * in the diagram below.
 * 
 * 
 * 
 * We may make the following moves:
 * 
 * 
 * 'U' moves our position up one row, if the position exists on the board;
 * 'D' moves our position down one row, if the position exists on the
 * board;
 * 'L' moves our position left one column, if the position exists on the
 * board;
 * 'R' moves our position right one column, if the position exists on the
 * board;
 * '!' adds the character board[r][c] at our current position (r, c) to the
 * answer.
 * 
 * 
 * (Here, the only positions that exist on the board are positions with letters
 * on them.)
 * 
 * Return a sequence of moves that makes our answer equal to target in the
 * minimum number of moves.  You may return any path that does so.
 * 
 * 
 * Example 1:
 * Input: target = "leet"
 * Output: "DDR!UURRR!!DDD!"
 * Example 2:
 * Input: target = "code"
 * Output: "RR!DDRR!UUL!R!"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= target.length <= 100
 * target consists only of English lowercase letters.
 * 
 */
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
