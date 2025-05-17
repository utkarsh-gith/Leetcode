// using min priority queue

class Solution {
public:
    long long findScore(vector<int>& nums) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> index;
        for(int i = 0;i < nums.size();i++){
            index.push({nums[i],i});
        }

        long long sum = 0;
        while(!index.empty()){

            int val = index.top().first;
            int idx = index.top().second;
            index.pop();

            if(nums[idx] == -1){
                continue;
            }

            sum += val;
            nums[idx] = -1;
            if(idx >= 1){
                nums[idx - 1] = -1;
            }
            if(idx + 1 < nums.size()){
                nums[idx + 1] = -1;
            }
        }

        return sum;
    }
};

// using sorted array

class Solution {
public:
    long long findScore(vector<int>& nums) {
        
        vector<pair<int,int>> index;
        for(int i = 0;i < nums.size();i++){
            index.push_back({nums[i], i});
        }

        sort(index.begin(), index.end());
        long long sum = 0;
        for(int i = 0;i < nums.size();i++){

            int val = index[i].first;
            int idx = index[i].second;

            if(nums[idx] == -1){
                continue;
            }

            sum += val;
            nums[idx] = -1;
            if(idx >= 1){
                nums[idx - 1] = -1;
            }
            if(idx + 1 < nums.size()){
                nums[idx + 1] = -1;
            }
        }

        return sum;
    }
};