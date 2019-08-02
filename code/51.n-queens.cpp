/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (40.45%)
 * Likes:    1040
 * Dislikes: 47
 * Total Accepted:    150.5K
 * Total Submissions: 372K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above.
 * 
 * 
 */
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<int> board(n, -10000);
        int i = 0, j = 0;
        while (i < n) {
            while (j < n) {
                if (isValid(i, j, board)) {
                    board[i] = j;
                    j = 0;
                    break;
                } else
                    ++j;
            }
            if (board[i] == -10000) {
                if (i == 0) {
                    break;
                } else {
                    --i;
                    j = board[i] + 1;
                    board[i] = -10000;
                    continue;
                }
            }
            if (i == n - 1) {
                vector<string> v(n, string(n, '.'));
                for (int k = 0; k < n; ++k) {
                    v[k][board[k]] = 'Q';
                }
                ret.push_back(v);
                j = board[i] + 1;
                board[i] = -10000;
                continue;
            }
            ++i;
            
        }
        return ret;
    }
    
    bool isValid(int x, int y, vector<int> board) {
        size_t size = board.size();
        for (int i = 0; i < size; ++i) {
            if (board[i] == y || abs(x - i) == abs(y - board[i])) {
                return false;
            }
        }
        return true;
    }
};

