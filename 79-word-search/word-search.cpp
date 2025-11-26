class Solution {
public:
    bool solve(int i, int j, int len, vector<vector<char>>& board, string& word, int k = 0) {
        if (k == len) return true;

        // bounds check
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return false;

        if (board[i][j] != word[k])
            return false;

        char temp = board[i][j];
        board[i][j] = '!'; // visited

        // try all 4 directions
        bool found =
            solve(i, j - 1, len, board, word, k + 1) ||
            solve(i, j + 1, len, board, word, k + 1) ||
            solve(i + 1, j, len, board, word, k + 1) ||
            solve(i - 1, j, len, board, word, k + 1);

        board[i][j] = temp; //backtrack

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int len = word.size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (solve(i, j, len, board, word))
                    return true;
            }
        }
        return false;
    }
};
