class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> charsMap;
        int result = 0;
        for(auto& ch:chars){
            charsMap[ch]++;
        }
        for(auto& word:words){
            unordered_map<char, int> tempMap = charsMap;
            bool isFormed = true;
            for(auto& w:word){
                if(--tempMap[w] == -1){
                    isFormed = false;
                    break;
                }
            }
            if(isFormed) result += word.length();
        }

        return result;
    }
};