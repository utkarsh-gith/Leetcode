// this code is slower because it has to find the value in the map 
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> count;
        int maxPairs = 0;

        for(int i = 0;i < nums.size(); i++){
            if(count[k - nums[i]] > 0){
                count[k - nums[i]]--;
                maxPairs++;
            }else{
                count[nums[i]]++;
            }
        }

        return maxPairs;
    }
};

// OR

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        int count = 0;

        while(i < j){
            if(nums[i] + nums[j] == k){
                count++;
                i++;
                j--;
            }else if(nums[i] + nums[j] > k){
                j--;
            }else{
                i++;
            }
        }

        return count;
    }
};