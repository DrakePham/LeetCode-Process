class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int t = 0;
        int b = matrix.size() - 1;
        for(int i = 0; i <= b; i++){
            if(search(matrix[i], target)) return true;
        }
        return false;
    }

    bool search(vector<int>& line, int target){
        int r = line.size() - 1;
        int l = 0;
        while(l <= r){
            int mid = l + (r - l)/2;
            int number = line[mid];
            if(number == target) return 1;
            else if(number > target) r = mid - 1;
            else l = mid + 1;
        }
        return 0;
    }


};