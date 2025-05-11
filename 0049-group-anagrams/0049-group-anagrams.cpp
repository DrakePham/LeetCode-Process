class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> temp = strs;
        for(auto& s:temp){
            sort(s.begin(), s.end());
        }
        unordered_map<string, vector<int>> map;
        for(int i = 0 ; i < strs.size(); i++){
            map[temp[i]].push_back(i);
        }
        vector<vector<string>> result;
        for(auto& strList:map){
            vector<string> list;
            for(auto& index: strList.second){
                list.push_back(strs[index]);
            }
            result.push_back(list);
        }

        return result;

    }

};


// sort all words
// group them and store their index by same sort order word
// create a new store with those index
// mlogm) time
// n space
// n space
