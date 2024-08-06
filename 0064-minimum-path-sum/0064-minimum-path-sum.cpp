class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rowLength= grid[0].size();
        int colLength= grid.size();
        // cout<<rowLength<<colLength;
        for(int i =0; i<colLength;i++){
            // cout<<i;
            for(int j=0;j<rowLength;j++){
                //most top left index
                if(i==0 and j==0){
                    continue;
                }else if (i==0){//most top index
                    grid[i][j] +=grid[i][j-1]; 
                }else if (j==0){ //most right index
                    grid[i][j] +=grid[i-1][j];
                }else{
                    grid[i][j] +=min(grid[i-1][j],grid[i][j-1]);
                    // cout<<"("<<i<<"'"<<j<<")"<<grid[i][j]<<"--";
                }
            }
        }

        return grid[colLength-1][rowLength-1];
    }
};

// understand :
// [[1]] return 1
    
// match:
// dp bottom up, time: n space 1

// plan:
// run in each row first, the value of the current index = minimun value of (the truely top value of the current index, the truly left of the current index 
// we need to check some special place like the most top, most left index