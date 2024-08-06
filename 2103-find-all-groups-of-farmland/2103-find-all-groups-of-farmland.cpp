class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> result;
        int rowL = land.size();
        int colL = land[0].size();
        // vector<vector<bool>> visited (rowL, vector<bool>(colL, false));
        for(int i = 0; i < rowL; i++){
            for(int j = 0; j < colL; j++){
                if(land[i][j] ==  1 ){
                    int g = i;
                    int h = j;
                    dfs(i, j, g, h, land);
                    result.push_back({i, j, g, h});
                }
            }
        }
        
        return result;
    }

    void dfs(int x, int y,int& g, int& h, vector<vector<int>>& land){
        if(land[x][y] == 0) return;
        int rowL = land.size();
        int colL = land[0].size();
        //x = 0; y out
        // bool c1 = ( x + 1 < rowL && land[x+1][y] == 0 && y + 1 == colL);
        // //x = out; y = 0;
        // bool c2 = ( y + 1 < colL && land[x][y+1] == 0 && x + 1 == rowL);
        // //x = out; y == out;
        // bool c3 = (x + 1 == rowL && y + 1 == colL);
        // //x = 0; y = 0
        // bool c4 = (x + 1 < rowL && land[x+1][y] == 0 && y + 1 < colL && land[x][y+1] == 0);

        // if(c1 || c2 || c3 || c4){
        //     g = x;
        //     h = y;
        //     return;
        // }
        land[x][y] = 0;
        g = max(g, x);
        h = max(h, y);

        for(auto& direction:directions){
            int newX = x + direction[0];
            int newY = y + direction[1];
            if(0 <= newX && newX < rowL && 0 <= newY && newY < colL) dfs(newX, newY, g, h, land);
        }
    }
};



// how it know it is the bottom right point of a farmland

// it is the bottom right point of a farmland
// when the right point of it is 0 or out of boundary and the down point of it is 0 or out of boundary;

// visited

// if land == 0 return
// if visited return;

// if (x+1 or land[x+1][y] == 0) and (y+1 out of boundary or land[x][y+1] == 0) update pair and then return

// for loop to expand in four directions
