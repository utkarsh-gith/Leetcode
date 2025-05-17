// Very Good question
// we have to find the minimum postive integer that is not in the array
// so an array of size n, if we have 1 to n integers, then smallest is n-1
// in case we have numbers greater than n or lrss than 0, the the smallest
// postive number lies between 1 to n
// replace all postive integer greater than n or less than 1 to n+1
// then if a number is less than n+1, mark that index to negative
// find the index which is non - negative will be the smallest postive integer

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] <= 0 || nums[i] > n){
                nums[i] = n+1;
            }
        }

        for(int i=0;i<n;i++){
            int num = abs(nums[i]);
            if(num <= n){
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }

        int i;
        for(i=0;i<n;i++){
            if(nums[i] > 0){
                break;
            }
        }

        return i+1;
    }
};

// OR

// using map which is not O(1) space, we can do it

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int j = 1;
        int n = nums.size();
        map<int,bool> check;

        for(int i=0;i<n;i++){
            check[nums[i]] = true;
        }
        while(check[j] == true){
            j++;
        }
        return j;
    }
};