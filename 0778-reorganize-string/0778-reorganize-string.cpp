class Solution {
public:

    vector<pair<int, char>> makeOcc(string& s){
        vector<pair<int, char>> occ;
        unordered_map<char, int> map;
        for(auto& c:s){
            map[c]++;
        }

        for(auto& p:map){
            occ.push_back({p.second, p.first});
        }
        return occ;
    } 

    bool isPossible(vector<pair<int, char>>& occ, int length){
        int mostOcc = occ[0].first;
        
        int restOccSum = length - mostOcc;
        if(mostOcc >= restOccSum + 2) return false;
        return true;
    }   

    string reorganizeString(string s) {
        vector<pair<int, char>> occ = makeOcc(s);
        sort(occ.begin(), occ.end(), greater<pair<int, char>>());
        int length = s.length();
        if(!isPossible(occ, length)) return "";
        string result = "";

        
      
        result += occ[0].second;
        occ[0].first -= 1;
                
        while(result.length() != length){
            sort(occ.begin(), occ.end(), greater<pair<int, char>>());
            int finalIndexResult = result.length() - 1;
            char finalLetterResult = result[finalIndexResult];
            for(int i = 0; i < occ.size(); i++){
                int letterOcc = occ[i].first;
                char letter = occ[i].second;
                if(letterOcc == 0) continue;
                else if(letter == finalLetterResult) continue;
                else{
                    result += letter;
                    occ[i].first = letterOcc - 1;
                    break;
                } 
            }
            
        }
        return result;
    }
};