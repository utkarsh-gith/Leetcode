class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        
        vector<int> res;
        for(auto num : nums){
            string s = to_string(num);
            for(auto c : s){
                res.push_back(c - '0');
            }
        }
        return res;
    }
};

// OR

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        
        vector<int> res;

        for(int i = nums.size() - 1; i >= 0; i--){

            int num = nums[i];
            
            while(num > 0){
                res.push_back(num % 10);
                num /= 10;
            }

        }

        reverse(res.begin(),res.end());
        return res;
    }
};