// Question Link: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

/*
Approach: XOR and Count Set Bits

- To convert `start` to `goal`, we need to flip the bits where they differ.
- XOR (`start ^ goal`) gives a number where:
    - Each bit is 1 if the bits in `start` and `goal` differ at that position.
- So, the number of 1's in the XOR result is the number of bit flips needed.

- Use Brian Kernighan’s Algorithm to count set bits in the XOR result:
    - Repeatedly do: x = x & (x - 1)
    - Increment count for each iteration.

Time Complexity: O(1) — since integers are 32-bit max  
Space Complexity: O(1)
*/

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start ^ goal;

        int count = 0;
        while(x > 0){
            x = x & (x - 1);
            count++;
        }

        return count;
    }
};