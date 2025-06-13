// Question Link: https://leetcode.com/problems/subsets/

// Based on expanding current answer set with each new number
/*
Approach:

- Initialize `ans` with an empty subset: {{}}.
- At each recursion step (indexed by `index`), clone the existing subsets,
  and for each clone, add `nums[index]` to create new subsets.
- Append these new subsets to `ans`.
- Recur until all elements are processed.

Time Complexity: O(2^n), Space Complexity: O(2^n)
*/

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


// For every new element, double the subsets
/*
Approach:

- Start with one empty subset: {{}}.
- For each number in `nums`, iterate over all existing subsets in `ans`.
- For each existing subset, create a new subset by adding the current number.
- Add all new subsets back to `ans`.

- This is a bottom-up approach that mimics recursion.

Time Complexity: O(2^n), Space Complexity: O(2^n)
*/

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


// Classic recursion: take or not take current element
/*
Approach:

- Use recursion with two choices at each index:
    - Exclude the current element and recurse.
    - Include the current element and recurse.
- When the index reaches the end, push the `output` subset to `ans`.
- This is a top-down backtracking approach.

Time Complexity: O(2^n), Space Complexity: O(n) recursion stack + O(2^n) result
*/
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


// Use binary representation to decide inclusion/exclusion
/*
Approach:

- Total number of subsets for n elements = 2^n.
- Loop from 0 to (2^n - 1), treating each number as a binary mask.
- If the j-th bit in i is set, include nums[j] in the current subset.
- This approach avoids recursion entirely and directly simulates subsets.

Time Complexity: O(n * 2^n), Space Complexity: O(2^n)
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int numOfSubsets = 1 << n;

        vector<vector<int>> res;
        for(int i = 0; i< numOfSubsets; i++){
            vector<int> ans;
            for(int j = 0;j < n; j++){
                if(i & (1 << j)){
                    ans.push_back(nums[j]);
                }
            }
            res.push_back(ans);
        }

        return res;
    }
};