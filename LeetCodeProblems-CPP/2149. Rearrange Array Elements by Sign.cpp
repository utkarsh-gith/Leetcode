// this method we take two pointers and find a positive
// and then a negative number one by one until last

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int i = 0;
        int j = 0;

        int n = nums.size();

        vector<int> res;

        while(res.size() != n){
            while(i<n){
                if(nums[i] > 0){
                    break;
                }
                i++;
            }

            res.push_back(nums[i]);
            i++;

            while(j<n){
                if(nums[j] < 0){
                    break;
                }
                j++;
            }

            res.push_back(nums[j]);
            j++;

        }

        return res;
    }
};

// here we take postive and negative positions like
// postive as 0 2 4
// and negative as 1 3 5

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int pos = 0;
        int neg = 1;

        int n = nums.size();

        vector<int> res(n,0);

        for(int i=0;i<n;i++){

            if(nums[i]>0){
                res[pos] = nums[i];
                pos += 2;
            }
            else{
                res[neg] = nums[i];
                neg += 2;
            }
        }

        return res;
    }
};