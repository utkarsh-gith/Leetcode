// first we find the range
// range is penalty
// smallest penalty is 1
// largest penalty will be the highest number in nums when maxOperations = 0
// now we apply binary search in the range
// take the mid element in the range nad check how many oprations are needed 
// to achieve the penalty
// start from first element in nums
// if nums[i] > penalty then 
// number of opeartions need to achieve the penalty = (nums[i]/penalty)
// if nums[i] % penalty == 0 then number of opeartions = (nums[i]/penalty) - 1
// complete the loop and compare with maxOperations
// if operations < maxOperations -> high = mid(present penalty)
// else low = mid + 1
// return low or high

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int high = 0;
        for(auto num : nums){
            if(high < num){
                high = num;
            }
        }

        int low = 1;
        
        while(low < high){

            int penalty = (high - low)/2 + low;
            int operations = 0;

            for(auto num : nums){
                if(penalty < num){

                    operations += num/penalty;
                    if (num % penalty == 0) {
                        operations--;
                    }
                
                }
            }

            if(operations > maxOperations){
                low = penalty + 1;
            }else{
                high = penalty;
            }
        }

        return high;
    }
};