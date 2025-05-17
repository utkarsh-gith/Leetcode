class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        
        int n = arr.size();
        if(n < 3){
            return false;
        }
        int count = 0;

        for(int i = 0;i < 3;i++){
            if(arr[i] % 2 == 1){
                count++;
            }
        }

        if(count == 3){
            return true;
        }

        for(int i = 3;i < n;i++){
            if(arr[i - 3] % 2 == 1){
                count--;
            }
            if(arr[i] % 2 == 1){
                count++;
            }
            if(count == 3){
                return true;
            }
        }

        return false;
    }
};

// OR

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        
        int n = arr.size();
        if(n < 3){
            return false;
        }
        
        for(int i = 0;i < n - 2;i++){
            if((arr[i] * arr[i + 1] * arr[i + 2]) % 2 == 1){
                return true;
            }
        }

        return false;
    }
};