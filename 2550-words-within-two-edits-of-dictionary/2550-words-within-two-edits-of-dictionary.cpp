class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int qL = queries.size();
        int dL = dictionary.size();
        vector<string> result;
        for(int i = 0 ; i < qL; i++){
            for(int j = 0; j < dL; j++){
                if(check(queries[i], dictionary[j])){
                    result.push_back(queries[i]);
                    break;
                }
            }
        }
        return result;
    }
    bool check(const string& query, const string& dic){
        
        int diff = 0;
        
        for(int i = 0 ; i < query.size() && i < dic.size(); i++){
            if(query[i] != dic[i]) diff++;
        }
        return diff <= 2;
    }
};