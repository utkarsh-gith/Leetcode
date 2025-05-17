class Solution {
public:
    bool isPrime(int n){

        if(n <= 1){
            return false;
        }
        if(n <= 3){
            return true;
        }
        if(n % 2 == 0){
            return false;
        }
        for(int i = 3;i * i <= n;i = i + 2){
            if(n % i == 0){
                return false;
            }
        }
        return true;

    }
    int diagonalPrime(vector<vector<int>>& nums) {
        
        int maxPrime = 0;
        int i = 0;
        int n = nums.size();

        while(i < n){
            if(maxPrime < nums[i][i]){
                if(isPrime(nums[i][i])){
                    maxPrime = nums[i][i];
                }
                
            }
            if(maxPrime < nums[i][n - i - 1]){
                if(isPrime(nums[i][n - i - 1])){
                    maxPrime = nums[i][n - i - 1];
                }
                
            }
            i++;
        }

        return maxPrime;
    }
};