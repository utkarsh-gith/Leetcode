class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> sumLeft(n,0);
        vector<int> sumRight(n,0);

        sumLeft[0] = nums[0];
        sumRight[n - 1] = nums[n - 1];

        for(int i = 1;i < n;i++){
            sumLeft[i] = sumLeft[i - 1] + nums[i];
            sumRight[n - i - 1] = sumRight[n - i] + nums[n - i - 1];
        }

        for(int i = 0;i < n;i++){
            if(sumLeft[i] == sumRight[i]){
                return i;
            }
        }

        return -1;
    }
};

// OR

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();
        int sum = 0;

        for(auto num : nums){
            sum += num;
        }

        int leftSum = 0;
        for(int i = 0;i < n;i++){
            if(leftSum * 2 == sum - nums[i]){
                return i;
            }
            leftSum += nums[i];
        }

        return -1;
    }
};