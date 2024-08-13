class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> map;
        for(auto& num:nums){
            map[num]++;
        }

        vector<vector<int>> pre;
        for(auto& m:map){
            pre.push_back({m.second, m.first});
        }
        sort(pre.begin(), pre.end(), [&](vector<int> a, vector<int> b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        vector<int> result;
        for(auto& p:pre){
            for(int i = 0; i < p[0]; i++){
                result.push_back(p[1]);
            }

        }
        return result;
    }
};