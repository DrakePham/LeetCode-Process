class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int result = 0;

        for(int i = 0 ; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'X'){
                    result += 1;
                    dfs(board, i, j);
                }
            }
        }
        
        return result;
    }
    void dfs(vector<vector<char>>& board, int x, int y){
        if(board[x][y] == '.') return;
        board[x][y] = '.';
        int m = board.size();
        int n = board[0].size();
        for(vector<int>& direction:directions){
            int newX = x + direction[0];
            int newY = y + direction[1];
            if(0 <= newX && newX < m && 0 <= newY && newY < n) dfs(board, newX, newY);
        }
    }
};