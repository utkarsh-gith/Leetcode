// initialise ans to {}
// then include and exclude to find the subset

class Solution {
public:

    void sets(vector<int> nums, vector<vector<int> >& ans,int index){

        if(index >= nums.size()){
            return;
        }

        vector<vector<int> > output = ans;
        for(int j = 0; j < ans.size(); j++){
            output[j].push_back(nums[index]);
        }
        for(int j = 0; j < output.size(); j++){
            ans.push_back(output[j]);
        }
        index++;

        sets(nums,ans,index);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int> > ans = {{}};
        vector<int> output;
        int index = 0;
        sets(nums, ans, index);

        return ans;
    }
};

// OR (same same but different)

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans ={{}};
        int n = nums.size();

        for(int i = 0;i < n;i++){

            int m = ans.size();

            for(int j = 0;j < m; j++){

                vector<int> subset = ans[j];
                subset.push_back(nums[i]);
                ans.push_back(subset);

            }
        }

        return ans;

    }
};

// OR 

class Solution {
public:

    void solve(vector<int> nums, vector<int> output, vector<vector<int>>& ans, int index){

        if(index >= nums.size()){

            ans.push_back(output);
            return;

        }

        //exclude
        solve(nums,output,ans,index+1);

        //include
        output.push_back(nums[index]);
        solve(nums,output,ans,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums,output,ans,index);

        return ans;

    }
};