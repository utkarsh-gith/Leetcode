class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();
        int max = 0;
        int curr = 0;
        int i = 0, j = 0;

        while(i<n){
            while(j<n && nums[j] == 1){
                j++;
            }

            curr = j - i;

            if(max < curr){
                max = curr;
            }

            if(i == j)
                j++;
                
            i = j; 
        }

        return max;

    }
};