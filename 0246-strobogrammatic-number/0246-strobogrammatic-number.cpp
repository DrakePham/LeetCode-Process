class Solution {
public:
    bool isStrobogrammatic(string num) {
        int l = 0;
        int r = num.length() - 1;
        while(l <= r){
            if(num[l] == '0' && num[r] == '0'){

            }else if(num[l] == '8' && num[r] == '8'){

            }else if((num[l] == '6' && num[r] == '9') || (num[l] == '9' && num[r] == '6')){

            }else if(num[l] == '1' && num[r] == '1'){}
            else{
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};