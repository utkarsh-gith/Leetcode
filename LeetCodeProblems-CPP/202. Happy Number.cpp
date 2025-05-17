class Solution {
public:
    bool isHappy(int n) {
        
        if(n == 1 || n == 7 || n == 13){
            return true;
        }

        while(1){

            if(n == 1){
                return true;
            }
            if(n == 16 || n == 25 || n == 36 || (n <= 9 && n != 7)){
                return false;
            }
            
            int temp = 0;
            while(n > 0){
                temp += (n % 10) * (n % 10);
                n /= 10;
            }
            n = temp;

        }
    }
};