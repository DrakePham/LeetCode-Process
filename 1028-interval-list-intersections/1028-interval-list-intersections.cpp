class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int firstListLength = firstList.size();
        int secondListLength = secondList.size();
        int p1 = 0;
        int p2 = 0;
        vector<vector<int>> result;
        
        while(p1 < firstListLength && p2 < secondListLength){
            int currentFirstListStart = firstList[p1][0];
            int currentFirstListEnd = firstList[p1][1];
            int currentSecondListStart = secondList[p2][0];
            int currentSecondListEnd = secondList[p2][1];

            if(currentFirstListStart <= currentSecondListEnd && currentSecondListStart <= currentFirstListEnd){
                result.push_back({max(currentFirstListStart, currentSecondListStart), min(currentFirstListEnd, currentSecondListEnd)});
            }
            if(currentFirstListEnd < currentSecondListEnd){
                p1++;
            }else{
                p2++;
            }
        }

        return result;
    }
};