// Direct Approach

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1){
            return 0;
        }
        if(nums[0] > nums[1])
            return 0;
        else if(nums[n-1]>nums[n-2])
            return n-1;
        
        int i;
        for(i=1;i<n-1;i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                break;
            }
        }
        return i;
    }
};


//Binary Search

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int low = 0;
        int high = nums.size()-1;
        while (low < high) {
            int mid = (low + high)/2;
            if (nums[mid] > nums[mid+1]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};