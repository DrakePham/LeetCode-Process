class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> map;
        for(auto& c:s) map[c]++;
        for(auto& c:t){
            map[c]--;
            if(map[c] == -1) return false;
        }
        return true;
    }
};