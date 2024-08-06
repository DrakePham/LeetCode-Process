class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map <int,int> map;
        for(auto i :nums){
            if(map[i]==1) return i;
            map[i]++;
        }
        return -1;
    }
};