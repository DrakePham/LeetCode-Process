class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size() == 0 && n == 1) return 1;
        unordered_map<int,int> map;
        unordered_map<int,int> map1;
        for(auto& t:trust){
            map[t[1]]++;
            map1[t[0]]++;
        }
        for(auto& m:map){
            if(m.second == n - 1 && map1.find(m.first) == map1.end()) return m.first;
        }
        return -1;
    }
};