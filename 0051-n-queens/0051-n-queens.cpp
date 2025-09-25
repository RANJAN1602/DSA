#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> result;
        if (n <= 0) {
            return result;
        }
        std::vector<std::string> board(n, std::string(n, '.'));
        std::vector<bool> cols(n, false);
        std::vector<bool> diag1(2 * n - 1, false);
        std::vector<bool> diag2(2 * n - 1, false);
        
        solve(0, n, board, result, cols, diag1, diag2);
        
        return result;
    }

private:
    void solve(int row, int n, std::vector<std::string>& board, 
               std::vector<std::vector<std::string>>& result,
               std::vector<bool>& cols, std::vector<bool>& diag1, std::vector<bool>& diag2) {
        
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            int diag1_idx = row + col;
            int diag2_idx = n - 1 + col - row;
            
            if (cols[col] || diag1[diag1_idx] || diag2[diag2_idx]) {
                continue;
            }

            board[row][col] = 'Q';
            cols[col] = true;
            diag1[diag1_idx] = true;
            diag2[diag2_idx] = true;

            solve(row + 1, n, board, result, cols, diag1, diag2);

            board[row][col] = '.';
            cols[col] = false;
            diag1[diag1_idx] = false;
            diag2[diag2_idx] = false;
        }
    }
};