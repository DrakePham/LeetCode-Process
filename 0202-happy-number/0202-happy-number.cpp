class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> map;
        
        while(true){
            int result = getSum(n);
            if (result==1) return true;
            if(map.find(result)!=map.end()) return false;
            map[result]++;
            n=result;
            
        }
        return false;
    }
    
    int getSum(int number){
        int sum=0;
        int i=0;
        while(number!=0){
            sum +=pow((number%10),2);
            number =number/10;
        }
        return sum;
    }
};

// understand:
// 1 return true
// 38 return false
// match:
// math and hashtable

// plan:
// have the function to calculate the square of each digit
// get the number and mod that number with 10 and add to sum variable untill the number reachs to 0

// use hash table to remember what we do, if we repeat the number in hash table one more time, meaning that we get the loop, so return false
    
// continue calculate the the number until we get 1 and return true
    
// Implement:
    