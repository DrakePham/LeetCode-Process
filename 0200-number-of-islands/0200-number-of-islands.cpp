class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        int colL= grid[0].size();
        int rowL= grid.size();
        vector<vector<bool>> visited(rowL, vector<bool> (colL, false));

        for(int i = 0; i < rowL; i++){
            for(int j = 0; j < colL; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    result++;
                    dfs(i, j, grid, visited);
                }
            }
        }

        return result;
    }

    void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& visited){

        if(grid[x][y] == '0') return;
        if(visited[x][y]) return;
        visited[x][y] = true;

        for(auto& direction:directions){
            int newX = x + direction[0];
            int newY = y + direction[1];
            int colL= grid[0].size();
            int rowL= grid.size();
            if(0 <= newX && newX < rowL && 0 <= newY && newY < colL) dfs(newX, newY, grid, visited);
        }
        
    }

};



