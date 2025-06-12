// Question Link: https://leetcode.com/problems/power-of-two/description/

/*
Approach: Bit Manipulation

- A number n is a power of two if:
    - It is greater than zero, and
    - It has exactly one bit set in its binary representation.
- Property:
    - For any power of two (e.g., 1, 2, 4, 8...), `n & (n - 1)` results in 0.
    - This works because:
        - Power of two:  1000
        - One less:       0111
        - AND:            0000
- So, the condition `(n > 0) && ((n & (n - 1)) == 0)` checks if `n` is a power of two.

Time Complexity: O(1), Space Complexity: O(1)
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && ((n & (n -1)) == 0);
    }
};


/*
Approach: Recursive Division by 2

- A number is a power of two if it can be repeatedly divided by 2 until it becomes 1.
- Base case:
    - If n == 1 → return true (2^0).
    - If n is odd and not 1 → return false.
- Recursive case:
    - If n is even, recursively call the function with n / 2.

This approach works only for positive integers.

Time Complexity: O(log n), Space Complexity: O(log n) (due to recursion stack)
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 1) {
            return true;
        }

        if (n % 2 != 0 || n <= 0) {
            return false;
        }
        
        return isPowerOfTwo(n / 2);
    }
};

/*
Approach: Iterative Division by 2

- A number is a power of two if it can be continuously divided by 2 until it becomes 1.
- Start with the given number `n` and loop:
    - If `n` is divisible by 2, divide it by 2.
    - If at any point `n` becomes odd (and not 1), return false.
- If the loop ends with `n == 1`, it is a power of two.

This avoids recursion and is safe for large inputs.

Time Complexity: O(log n), Space Complexity: O(1)
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        while (n % 2 == 0) {
            n /= 2;
        }
        
        return n == 1;
    }
};