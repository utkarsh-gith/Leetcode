// Question Link: https://leetcode.com/problems/counting-bits/

/*
Approach: Using Dynamic Programming + Brian Kernighan’s Observation

- The number of set bits in `i` can be derived from:
  dp[i] = dp[i & (i - 1)] + 1
- This works because `i & (i - 1)` removes the lowest set bit from `i`.
- Base Case: dp[0] = 0
- Recursively or iteratively fill the dp array for 1 to n.

Recursive Version:
- Call a helper function that fills dp[n] using the above recurrence.
- Must pass dp by reference to persist changes.

Iterative Version:
- Loop from 1 to n and use the recurrence to fill dp[i].

Time Complexity: O(n), Space Complexity: O(n)
*/
class Solution {
public:
    void solver(vector<int>& dp, int n){
        if(n >= dp.size()){
            return;
        }

        int k = n & (n - 1);
        dp[n] = dp[k] + 1;

        solver(dp, n + 1);
    }
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = 0;

        solver(dp, 1);

        return dp;
    }
};


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = 0;

        for(int i = 1;i <= n; i++){
            dp[i] = dp[i & (i - 1)] + 1;
        }

        return dp;
    }
};


/*
Approach: Dynamic Programming Using Right Shift and Least Significant Bit

- The idea is to use the relation:
  dp[i] = dp[i >> 1] + (i & 1)
  
- Explanation:
  - `i >> 1` is equivalent to `i / 2`, so it reuses the bit count of a smaller number.
  - `(i & 1)` checks if the least significant bit of `i` is set (i.e., if `i` is odd).
  - So, each dp[i] is just:
      → the number of set bits in i/2,
      → plus 1 if i is odd (last bit is 1).

- Base case: dp[0] = 0

This approach builds up the solution from 0 to n using previously computed results.

Time Complexity: O(n), Space Complexity: O(n)
*/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = 0;

        for(int i = 1;i <= n; i++){
            dp[i] = dp[i >> 1] + (i & 1);
        }

        return dp;
    }
};