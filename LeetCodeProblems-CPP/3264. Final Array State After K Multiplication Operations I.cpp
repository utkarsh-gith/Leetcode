class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        for(int i = 0;i < nums.size(); i++){
            minHeap.push({nums[i],i});
        }

        while(k > 0){

            int idx = minHeap.top().second;
            minHeap.pop();

            nums[idx] *= multiplier;
            minHeap.push({nums[idx],idx});
            k--;
        }

        return nums;
    }
};

// OR

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        while(k--){

            int minIdx = 0;

            for(int i = 1;i < nums.size(); i++){
                if(nums[i] < nums[minIdx]){
                    minIdx = i;
                }
            }

            nums[minIdx] *= multiplier;
        }

        return nums;
    }
};