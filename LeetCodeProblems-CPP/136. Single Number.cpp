// Question link: https://leetcode.com/problems/single-number/submissions/1662184682/

/*
Approach:

- XOR of a number with itself is 0: (a ^ a = 0)
- XOR of a number with 0 is the number: (a ^ 0 = a)
- XOR is both associative and commutative.

So, if all numbers appear twice except one, doing XOR over the entire array
will cancel out the duplicates and leave only the unique number.

Steps:
- Initialize `s = 0`.
- Iterate through each number and do `s ^= nums[i]`.
- The final value of `s` will be the number that appears once.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int s = 0;
        for(int& num : nums){
            s ^= num;
        }
        return s;
    }
};


/*
Approach: Frequency Counting Using Hash Map

- Create an unordered_map to store the frequency of each number.
- Traverse the array and count occurrences of each element.
- Traverse the map to find the element with a frequency of 1.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        for (auto& it : freq) {
            if (it.second == 1) {
                return it.first;
            }
        }

        return 0; // This line is technically unreachable if input is valid
    }
};