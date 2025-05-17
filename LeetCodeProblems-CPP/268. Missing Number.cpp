// Use XOR (^) operator

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int s = n;
        for(int i=0;i<n;i++){
            s = s ^ nums[i] ^ i;
        }
        return s;
    }
};