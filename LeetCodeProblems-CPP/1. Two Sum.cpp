class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,bool> visited;
        for(int i=0;i<nums.size();i++){
            if(visited[target-nums[i]]==true){
                for(int j=0;j<i;j++){
                    if(nums[j]==target-nums[i]){
                        return {j,i};
                    }
                }
            }
            visited[nums[i]] = true;
        }
        return {};
    }
};