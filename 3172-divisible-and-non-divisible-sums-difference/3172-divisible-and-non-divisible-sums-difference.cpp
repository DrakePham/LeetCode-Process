class Solution {
public:
    int differenceOfSums(int n, int m) {
        int divisibleNumber = n/m;
        int num2 = m*(1+divisibleNumber)*divisibleNumber/2;
        int sumAllNumber = (n+1)*n/2;
        return sumAllNumber - 2*num2;
    }
};

// n = 10, m = 3
// n/m  = 10/3 = 3
// num2 = 3*4*3/2 = 18
// sumAllNumber = 11*10/2 = 55.   | 30
// return 55-36 = 19



// 1- 10
// 10 /3 = 3
// n1 = 3(1+2+3) = 3(3 + 1)3/2
// 1+2+3+4 = 5*4/2