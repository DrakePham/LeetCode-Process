class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
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