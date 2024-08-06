class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length = digits.size();
        bool plusOne =false;
        for(int i = length - 1; i >=0; i--){
            if(i == length - 1 || (plusOne)){
                digits[i] ++;
                if (digits[i] == 10){
                    digits[i] = 0;
                    plusOne = true;
                }else{
                    plusOne = false;
                    break;
                }
            }
        }
        if (plusOne){
            digits.push_back(0);
            digits[0] = 1;
        }
        return digits;
    }
};