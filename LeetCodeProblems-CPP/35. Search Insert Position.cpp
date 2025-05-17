// Idea: Array is sorted, so use binary search. Also if the element is not present low will be the postion where the element has to be inserted.
// Time Complexity: O(log n)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1,m;
        while(l<=h)
        {
            m=(l+h)/2;
            if(nums[m]==target)
                return m;
            else if(nums[m]<target)
                l=m+1;
            else
                h=m-1;

        }
        return l;
    }
};
