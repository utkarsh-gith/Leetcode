// Using XOR

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int s = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            s ^= nums[i];
        }

        return s;
    }
};

// Using Binary Search

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int mid;

        while(low < high){
            
            mid = low + (high - low)/2;

            if(mid % 2 == 1){
                mid--;
            }
            if(nums[mid] == nums[mid + 1]){
                low = mid + 2;
            }
            else{
                high = mid;
            }
        }

        return nums[low];
    }
};