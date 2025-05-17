class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {

        int n = nums.size();
        long long count = nums.size();

        int i = 0;
        while (i < n) {

            long long window_size = 1;
            int j = i;
            int minIdx = i;
            int maxIdx = i;
            int minNum = nums[i];
            int maxNum = nums[i];

            while (j + 1 < n) {

                if(nums[j + 1] <= minNum){
                    minIdx = j + 1;
                    minNum = nums[j + 1];
                }
                if(nums[j + 1] >= maxNum){
                    maxIdx = j + 1;
                    maxNum = nums[j + 1];
                }

                if(maxNum - minNum <= 2){
                    j++;
                    window_size++;
                }else{
                    break;
                }  
            }
            
            if(window_size > 1){
                count += (window_size * (window_size - 1))/2;
                if(j != n - 1){
                    i = (minIdx < maxIdx) ? minIdx + 1 : maxIdx + 1;
                    int num = j - i;
                    count -= (num * (num + 1))/2;
                }else{
                    break;
                }   
            }else{
                i++;
            }
 
        }

        return count;
    }
};

