class Solution {
public:

    bool isDigit(string& word, int& index){
        if('0' <= word[index] && word[index] <= '9') return true;
        return false;
    }

    int getNumber(string& word, int& index){
        string numberStr = "";
        while(isDigit(word, index)){
            numberStr += word[index];
            index++;
        }
        int number = stoi(numberStr);
        return number;
    }

    bool isLeadingZero(string& word, int index){
        if(word[index] == '0') return true;
        return false;
    }

    bool validWordAbbreviation(string word, string abbr) {
        word += 'a';
        abbr += 'a';
        int indexAbbr = 0;
        int indexWord = 0;
        int lengthWord = word.length();
        int lengthAbbr = abbr.length();
        while(indexAbbr < lengthAbbr || indexWord < lengthWord){
            int number = 0;
            if(isDigit(abbr, indexAbbr)) {
                if(isLeadingZero(abbr, indexAbbr)) return false;
                number = getNumber(abbr, indexAbbr);
            }
            indexWord += number;
            if(indexWord < lengthWord && indexAbbr < lengthAbbr && word[indexWord] == abbr[indexAbbr]){
                indexAbbr++;
                indexWord++;
                continue;
            }else{
                return false;
            }

        }
        return true;
    }
};
