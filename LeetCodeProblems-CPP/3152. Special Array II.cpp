class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();
        int m = queries.size();
        vector<bool> res;

        bool parity = (nums[0] % 2 == 0);
        int count = 0;
        nums[0] = count;

        for(int i = 1;i < n; i++){

            if(parity != (nums[i] % 2 == 0)){
                parity = !parity;
                nums[i] = count;
            }else{
                nums[i] = ++count;
            }

        }

        for(int i = 0;i < m;i++){
            if(nums[queries[i][0]] == nums[queries[i][1]]){
                res.push_back(true);
            }else{
                res.push_back(false);
            }
        }

        return res;
    }
};