class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int findMaxFish(vector<vector<int>>& grid) {
        int result = 0;
        int rowL = grid.size();
        int colL = grid[0].size();
        for(int i = 0; i < rowL; i++){
            for(int j = 0; j < colL; j++){
                int curFish = 0;
                dfs(i, j, curFish, grid);
                result = max(curFish, result);
            }
        }
        return result;
    }

    void dfs(int x, int y, int& curFish,vector<vector<int>>& grid){
        if(grid[x][y] == 0) return;
        int rowL = grid.size();
        int colL = grid[0].size();
        curFish += grid[x][y];
        grid[x][y] = 0;
        for(auto& direction:directions){
            int newX = x + direction[0];
            int newY = y + direction[1];
            if (0 <= newX && newX < rowL && 0 <= newY && newY < colL) dfs(newX, newY, curFish, grid);
        }
    }
};