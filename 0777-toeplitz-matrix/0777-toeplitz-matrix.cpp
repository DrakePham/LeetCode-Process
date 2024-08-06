class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int lengthRow = matrix[0].size();
        int lengthCol = matrix.size();
        if (lengthCol==1) return true;
        for(int i=0;i<lengthCol-1;i++){
            for(int j=0;j<lengthRow-1;j++){
                if(matrix[i][j]!=matrix[i+1][j+1]) return false;
            }
        }
        return true;
    }
};

// understand:
// [1] return true
// [[1,2,3,4]] return true
// time:n space:the length of row
// match:

// plan:
// compare the second row with the first row
//     n: will be the length of row
//     compare from 1 to n-1 element of the first row with the 2 to n element of the second element 
// evaluate:
// [[1,2,3,4],
// [5,1,2,3],
// [9,5,1,2]]
// row=4
// col==3
// 1(0,0)=1(1,1)|2(0,1)=2(1,2)