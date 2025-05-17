/* this question we have to first find the range in which the solution will lie.
it lies between the largest number in the array and the sum of all the elements in the array
we then apply binary search
we take the mid element in the range and check if we can accomodate all the integers within k subgroups less than or equal to mid
if we can the we update our result to mid and change high to mid - 1 and apply binary search again
if we cannot we change low to mid + 1 and aplly binary search again*/


class Solution {
public:

    int canSplit(vector<int>& nums, int mid, int k){

        int subArray = 1;
        int curSum = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            curSum += nums[i];
            if(curSum > mid){
                subArray++;
                curSum = nums[i];
            }
        }

        if(subArray <= k){
            return 1;
        }
        else{
            return 0;
        }
    }

    int splitArray(vector<int>& nums, int k) {

        int n = nums.size();
        int low = 0;
        int high = 0;

        for(int i=0;i<n;i++){
            high += nums[i];
            if(nums[i] > low){
                low = nums[i];
            }
        }

        int res = high;

        while(low <= high){

            int mid = low + (high - low)/2;

            if(canSplit(nums,mid,k)){
                res = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return res;

    }
};