class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        
        vector<int> arr(n + 1,1);
        for(auto ban : banned){
            if(ban <= n){
                arr[ban] = 0;
            }
        }

        int count = 0;
        int sum = 0;

        for(int i = 1;i < n + 1;i++){
            
            if(arr[i]){
                sum += i;
                if(sum <= maxSum){
                    count ++;
                }else{
                    break;
                }
            }
            
        }

        return count;
        
    }
};