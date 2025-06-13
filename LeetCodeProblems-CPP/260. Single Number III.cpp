// Question Link: https://leetcode.com/problems/single-number-iii/

/*
Approach: Bit Manipulation (XOR Partitioning)

- Step 1: XOR all numbers → let the result be `n`.
  - This gives `n = a ^ b`, where a and b are the two unique numbers.
- Step 2: Find any set bit in `n` (i.e., a bit where `a` and `b` differ).
  - `n & (-n)` or `(n & (n - 1)) ^ n` isolates the rightmost set bit.
- Step 3: Partition the array into two groups:
  - One group where this bit is set.
  - One group where it's not.
- Step 4: XOR elements within each group.
  - All duplicate elements cancel out.
  - Only `a` and `b` remain — one in each group.

Time Complexity: O(n)  
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long n = 0;
        for(int& num : nums){
            n ^= num;
        }

        n = (n & (n - 1)) ^ n;
        int b1 = 0;
        int b2 = 0;

        for(int& num : nums){
            if(n & num){
                b1 ^= num;
            }else{
                b2 ^= num;
            }
        }

        return {b1, b2};
    }
};