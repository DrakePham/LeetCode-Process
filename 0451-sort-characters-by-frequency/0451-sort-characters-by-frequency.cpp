class Solution {
public:
    string frequencySort(string s) {
        int lengthOfInput=s.length();
        if (lengthOfInput==1) return s;
        unordered_map <char,int> map;
        for(auto eachChar:s){
            map[eachChar]++;
        }
        
        priority_queue<pair<int,char>> maxHeap;
        
        for(auto frequentChar:map){
            maxHeap.push({frequentChar.second,frequentChar.first});
        }
        string result;
        while(!maxHeap.empty()){
            int numberChar=maxHeap.top().first;
            while(numberChar--){
                result.push_back(maxHeap.top().second);
            }
            maxHeap.pop();
        }
        return result;
    }
};

// understand:
// ["t"] return ["t"]
// ["fss"] return ["ssf"]
// time:n
// space:n
// match:
// maxHeap=>time: nlogn, space:n
// hashtable =>time:n, space:1
    
// plan:
// add bu hashtable time:n space:1
// maxHeap 70logn space 1
// pop maxHeap time: 1
//  time: n
//  space :1

