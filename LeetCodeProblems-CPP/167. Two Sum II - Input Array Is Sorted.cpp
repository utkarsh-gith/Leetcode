// Idea: check the extreme ends of the vector: 
//       if they are equal to target then return the indices
//       if sum is greater than target then decrement the last index
//       if sum is less than targer then increment the first index


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j=numbers.size()-1;
        int sum;
        while (i < j) {
            sum = numbers[i]+numbers[j];
            if ( sum == target)
                return {i+1, j+1};
            else if (sum > target)
                j--;
            else
                i++;
        }
        return {};
    }
};
