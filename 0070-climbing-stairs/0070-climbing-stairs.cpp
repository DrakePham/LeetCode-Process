class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2; 
       vector<int> dp(n + 1, 0);
       
       dp[1] = 1;
       dp[2] = 2;

       for(int i = 3 ; i <= n ; i++){
            dp[i] = dp[i-1] + dp[i - 2];
       
       }
       return dp[n];
    }

    
};

/*
dp[i] is the number of distinct to climb to the i stage

dp[1] = 1
dp[2] = 2
dp[3] = 3 = dp[2] +dp[1]
dp[4] = dp[3] + dp[2] = 5
1111
121
211

112
22




*/