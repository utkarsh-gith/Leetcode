// Question Link: https://leetcode.com/problems/single-number-ii/description/

/*
Approach: Bitwise Counting (Mod 3)

- The problem states that every element appears three times except one.
- For each bit position (0 to 31), count how many times that bit is set across all numbers.
- If the count is not divisible by 3, it means that the unique number has that bit set.
- Reconstruct the unique number by setting those bits in the result.

This works because the repeated elements (appearing 3 times) contribute multiples of 3 to each bit position,
and only the unique element contributes the extra 1.

Time Complexity: O(32 * n) = O(n)  
Space Complexity: O(1) — uses a constant number of variables
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        
        for(int bitIdx = 0; bitIdx <= 31; bitIdx++){
            int count = 0;

            for(int& num : nums){
                if(num & (1 << bitIdx)){
                    count++;
                }
            }

            if(count % 3 != 0){
                ans |= (1 << bitIdx);
            }
        }

        return ans;
    }
};


/*
Approach: Sorting + Group Checking

- Sort the array. All numbers appearing 3 times will group together.
- Loop through the array in steps of 3:
    - At each step, check if the current element (nums[i]) is equal to the previous one (nums[i - 1]).
    - If not, nums[i - 1] is the unique element and should be returned.
- If the loop completes without returning, the unique element must be the last one.

Time Complexity: O(n log n) — due to sorting  
Space Complexity: O(1) — in-place sort
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = 1;i < n; i+=3){
            if(nums[i] != nums[i - 1]){
                return nums[i - 1];
            }
        }

        return nums[n - 1];
    }
};

/*
Approach: Bitmasking with Two Counters (Ones and Twos)

- Every number except one appears exactly three times.
- Use two variables `ones` and `twos` to track the count of each bit modulo 3.
  - `ones` holds bits that have appeared once.
  - `twos` holds bits that have appeared twice.
- For each number:
    1. Update `ones`: toggle current bits, then remove bits that are already in `twos`.
    2. Update `twos`: toggle current bits, then remove bits that are now in `ones`.
- This ensures:
    - On 1st occurrence → bit goes to `ones`.
    - On 2nd → moves to `twos`.
    - On 3rd → cleared from both.
- After all elements are processed, `ones` contains the unique number that appeared only once.

Time Complexity: O(n)  
Space Complexity: O(1)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;

        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }

        return ones;
    }
};