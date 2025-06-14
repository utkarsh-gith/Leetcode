// Question Link: https://leetcode.com/problems/sum-of-two-integers/

/*
Approach: Bitwise Addition Without Using '+' or '-'

- The goal is to add two integers `a` and `b` without using arithmetic operators.
- This can be achieved using bitwise operations:

  1. XOR (^) simulates addition **without carry**:
     - Example: 5 ^ 3 = 6 (binary addition without carrying)

  2. AND (&) followed by left shift (<<) simulates the **carry**:
     - (a & b) finds carry bits
     - (a & b) << 1 shifts them to their correct position

- Repeat this process:
    - Update `a` with the XOR result (partial sum)
    - Update `b` with the new carry
- Stop when `b` becomes 0 (no more carry)

- Works for both positive and negative numbers due to two's complement representation.

Time Complexity: O(1) — at most 32 iterations (for 32-bit integers)  
Space Complexity: O(1)
*/
class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
            int carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }

        return a;
    }
};

class Solution {
public:
    int getSum(int a, int b) {
        int num = a ^ b;
        int carry = a & b;

        while(carry != 0){
            carry = carry << 1;
            int temp = num ^ carry;
            carry = num & carry;
            num = temp;
        }

        return num;

    }
};