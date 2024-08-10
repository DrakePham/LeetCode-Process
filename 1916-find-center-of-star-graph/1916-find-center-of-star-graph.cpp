class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> map;
        for(auto& edge:edges){
            map[edge[0]]++;
            map[edge[1]]++;
        }
        for(auto& m:map){
            if(m.second == edges.size()) return m.first;
        }
        return -1;
    }
};