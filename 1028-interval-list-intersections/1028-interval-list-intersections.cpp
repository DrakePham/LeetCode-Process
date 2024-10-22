class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int firstListLength = firstList.size();
        int secondListLength = secondList.size();
        
        if(firstListLength == 0 || secondListLength == 0) return {};


        sort(firstList.begin(), firstList.end());
        sort(secondList.begin(), secondList.begin());
        
        int p1 = 0;
        int p2 = 0;
        vector<vector<int>> result;
        while(p1 < firstListLength && p2 < secondListLength){
            int currentFirstListStart = firstList[p1][0];
            int currentFirstListEnd = firstList[p1][1];
            int currentSecondListStart = secondList[p2][0];
            int currentSecondListEnd = secondList[p2][1];
            cout<<currentFirstListStart<<currentSecondListStart<<endl;
            cout<<currentFirstListEnd<<currentSecondListEnd<<endl;

            if(currentFirstListEnd < currentSecondListStart){
                p1++;
                continue;
            }else if(currentSecondListEnd < currentFirstListStart){
                p2++;
                continue;
            }
            
            if(currentFirstListStart <= currentSecondListStart && currentFirstListEnd <= currentSecondListEnd){
                result.push_back({currentSecondListStart, currentFirstListEnd});
                p1++;
            }
            else if(currentFirstListStart <= currentSecondListStart && currentFirstListEnd > currentSecondListEnd){
                result.push_back({currentSecondListStart, currentSecondListEnd});
                p2++;
            }else if(currentFirstListStart > currentSecondListStart && currentFirstListEnd <= currentSecondListEnd){
                result.push_back({currentFirstListStart, currentFirstListEnd});
                p1++;
            }else{
                result.push_back({currentFirstListStart, currentSecondListEnd});
                p2++;
            }   
        }

        return result;
    }
};