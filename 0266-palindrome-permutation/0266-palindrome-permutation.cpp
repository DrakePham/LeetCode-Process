class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> table (26, 0);
        for(auto& letter: s){
            table[letter - 'a'] += 1;
        }
        
        int oddLetter = 0;
        for(auto& occ: table){
            if(occ % 2 == 1) oddLetter += 1;
        }
        
        return oddLetter <= 1;

    }
};
// aabbbc -> false
// a: 2
// b: 3
// c: 1

// if all of number of a letter are even->  return true |aabb -> true -> oddLetter == 0
// if only 1 letter with odd number and the rest are even -> true ->oddLetter == 1

// oddLetter = 0

// return false if the oddLetter > 1
