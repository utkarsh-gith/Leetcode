// using extra space

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        vector<int> num;
        for(int i = 0;i < n;i++){
            num.push_back(nums[i]);
            num.push_back(nums[i + n]);
        }
        return num;
    }
};

// using no extra space

