class Solution {
public:
    int differenceOfSums(int n, int m) {
        int divisibleNumber = n/m;
        int num2 = m*sumFrom1toN(divisibleNumber);
        int sumAllNumber = sumFrom1toN(n);
        return sumAllNumber - 2*num2;
    }
    int sumFrom1toN(int n){
        return (n+1)*n/2;
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