class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> node (n + 2, 0);
        for(auto& edge:edges){
            node[edge[0]]++;
            node[edge[1]]++;
        }
        for(int i = 1; i <= n + 1; i++){
            if(node[i] == n) return i;
        }
        return -1;
    }
};