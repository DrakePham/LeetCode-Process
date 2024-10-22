class Solution {
public:
    int maximumSwap(int num) {
        
        string number = to_string(num);
        int length = number.length();
        char curMaxNumber = number[length - 1];
        int currentMaxIndex = length - 1;
        pair<int, int> swapPlaces = {length - 1, length - 1};
        for(int i = length - 1; i >= 0; i--){
            char currentNumber = number[i];
            if(curMaxNumber < currentNumber){
                curMaxNumber = currentNumber;
                currentMaxIndex = i;
            }else if (curMaxNumber > currentNumber){
                swapPlaces = {i, currentMaxIndex};
            }
        }
        swap(number[swapPlaces.first], number[swapPlaces.second]);
        return stoi(number);
    }
};