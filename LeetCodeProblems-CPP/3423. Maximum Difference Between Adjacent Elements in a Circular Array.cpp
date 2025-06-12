// Question Link: https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/?envType=daily-question&envId=2025-06-12

/*
Approach: Circular Maximum Adjacent Difference

- The goal is to find the maximum absolute difference between adjacent elements in the array.
- The array is treated as **circular**, meaning the last element is also adjacent to the first.
- Iterate through the array from index 0 to n - 1:
    - For each element at index i, compare it with the next element at (i + 1) % n.
    - Use `abs(nums[i] - nums[(i + 1) % n])` to get the absolute difference.
    - Track the maximum difference seen so far.

Time Complexity: O(n), Space Complexity: O(1)
*/

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = 0;

        for(int i = 0; i < n; i++){
            maxDiff = max(maxDiff, abs(nums[i % n] - nums[(i + 1) % n]));
        }

        return maxDiff;
    }
};