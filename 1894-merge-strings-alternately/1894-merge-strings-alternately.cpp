class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";

        int p1 = 0;
        int p2 = 0;
        while(p1 < word1.length() && p2 < word2.length()){
            result += word1[p1];
            result += word2[p2];
            p1++;
            p2++;
        }

        while(p1 < word1.length()){
            result += word1[p1];
            p1++;
        }

        while(p2 < word2.length()){
            result += word2[p2];
            p2++;
        }

        return result;
    }
};