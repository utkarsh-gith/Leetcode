// Question Link:

/*
Approach:
- The array nums[i] = start + 2 * i forms an arithmetic progression with step size 2.
- The XOR of such a sequence follows a repeating pattern every 8 elements.
- Instead of iterating through the entire array, we use precomputed XOR behavior based on `x % 8`.
- `forward(x)` computes the XOR from `x` forward, based on its position in the pattern.
- `backward(x)` computes the XOR from `x` backward, again using `x % 8`.
- Final result is: forward(start) ^ backward(end), where end = start + 2*(n-1).

This avoids any loops and uses only constant space.

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    int forward(int x){
        int y = x % 8;
        if((y == 0) || y == 1) return 0;
        if((y == 2) || y == 3) return x ^ (x + 2) ^ (x + 4);
        if((y == 4) || y == 5) return x ^ (x + 2);
        return x;
    }
    int backward(int x){
        int y = x % 8;
        if((y == 0) || y == 1) return x;
        if((y == 2) || y == 3) return x ^ (x - 2);
        if((y == 4) || y == 5) return x ^ (x - 2) ^ (x - 4);
        return 0;
    }
    int xorOperation(int n, int start) {
        int s = start, e = start + (2 * (n - 1));
        return forward(s) ^ backward(e);
    }
};

/*
Approach:
- Generate the full array implicitly by calculating each element using: nums[i] = start + 2 * i.
- XOR all these elements in a loop and return the result.

This approach is straightforward and easy to implement but has linear time complexity.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 0;
        for(int i = 0;i < n; i++){
            ans ^= (start + 2 * i);
        }
        return ans;
    }
};