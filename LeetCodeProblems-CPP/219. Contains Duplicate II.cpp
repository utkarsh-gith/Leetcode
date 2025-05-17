class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        map<int, int> check;
        int n = nums.size();

        for(int i = 0;i < n;i++){
            if(check.contains(nums[i])){ // or if(check.find(nums[i]) != check.end())
                if(i - check[nums[i]] <= k){
                    return true;
                }
            }
            check[nums[i]] = i;
        }
        return false;

    }
};