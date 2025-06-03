class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> temp(n);

        for(int i=0;i<n;i++){
            temp[(i+k)%n] = nums[i];
        }

        nums = temp;
    }
};

//OR

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)

// OR Manual Swaps
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        int i = 0, j = n - 1;
        while(i < j){
            swap(nums[i++], nums[j--]);
        }

        i = 0, j = k - 1;
        while(i < j){
            swap(nums[i++], nums[j--]);
        }

        i = k, j = n - 1;
        while(i < j){
            swap(nums[i++], nums[j--]);
        }
    }
};