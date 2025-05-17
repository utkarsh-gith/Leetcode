class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        if(n == 0){
            return {-1,-1};
        }

        int low = 0;
        int high = n -1;

        while(low<=high){

            int mid = (high - low)/2 + low;

            if(nums[mid] == target){

                low = mid;
                high = mid;

                while(low>0){
                    if(nums[low-1] != target){
                        break;
                    }
                    else{
                        low--;
                    }
                }
                while(high<n-1){
                    if(nums[high+1] != target){
                        break;
                    }
                    else{
                        high++;
                    }
                }
                return {low,high};

            }

            else if(nums[mid] < target){
                low = mid + 1;
            }

            else{
                high = mid - 1;
            }

        }

        return {-1,-1};
    }
};