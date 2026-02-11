class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

    bool find(vector<vector<char>>& board, int i, int j, int idx, string &word) {

        // Boundary check FIRST
        if(i < 0 || j < 0 || i >= m || j >= n) return false;

        // Already visited
        if(board[i][j] == '$') return false;

        // Character mismatch
        if(board[i][j] != word[idx]) return false;

        // Found all characters
        if(idx == word.size() - 1) return true;

        char temp = board[i][j];
        board[i][j] = '$';  // mark visited

        for(auto &dir : directions){
            int ni = i + dir[0];
            int nj = j + dir[1];

            if(find(board, ni, nj, idx + 1, word))
                return true;
        }

        board[i][j] = temp; // restore
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0] && find(board, i, j, 0, word))
                    return true;
            }
        }
        return false;
    }
};