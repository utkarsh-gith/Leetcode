//two solutions

//1.
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();
        int c = 0;
        int k = 0;

        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                c++;
            }
            else{
                nums[k++] = nums[i];
            }
        }

        for(int i=k;i<n;i++){
            nums[i] = 0;
        }
    }
};

//2.
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int i=0;
        
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=0){
                swap(nums[i],nums[j]);
                i++;
            }
        }

    }
};