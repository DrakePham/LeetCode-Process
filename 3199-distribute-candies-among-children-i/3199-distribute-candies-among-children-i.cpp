class Solution {
public:
    int distributeCandies(int n, int limit) {
        int numberOfWay = 0;
        for(int a = 0; a <= limit; a++){
            int currentCandies = a;
            for(int b = 0; b <= limit; b++){
                currentCandies += b;
                for(int c = 0; c <= limit; c++){
                    currentCandies += c;
                    if(currentCandies == n) numberOfWay ++;
                    currentCandies -= c;
                }
                currentCandies -= b;
            }
        }

        return numberOfWay;
    }
};