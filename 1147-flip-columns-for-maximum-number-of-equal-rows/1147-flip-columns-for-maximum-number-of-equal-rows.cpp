class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        map<string, int> nums;
        for(int i=0; i<n; i++) {
            string st, ts;
            for(int j=0; j<m; j++) {
                //aab == bba
                int number = matrix[i][j];
                st += (number == 0) ? "0" : "1";
                ts += (number == 0) ? "1" : "0";
            }
            nums[st]++;
            nums[ts]++;
        }
        int ans = 0;
        for(auto x: nums) {
            ans = max({ans, x.second});
        }
        return ans;
    }
};




