// DP

class Solution {
public:
    int fib(int n) {
       
       if(n == 0 || n == 1){
        return n;
       }

       vector<int> dp(n+1);
       dp[0] = 0;
       dp[1] = 1;

       for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
       }

       return dp[n];
    }
};

// Iterative 

class Solution {
public:
    int fib(int n) {
        
        int n1 = 0;
        int n2 = 1;

        if(n == 0){
            return 0;
        }
        int i = 2;
        while(i <= n){
            int temp = n1 + n2;
            n1 = n2;
            n2 = temp;
            i++;
        }

        return n2;
    }
};

// Recursive

class Solution {
public:
    int fib(int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }

        return fib(n-1) + fib(n-2);
    }
};