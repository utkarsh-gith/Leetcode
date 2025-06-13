// Question Link: https://leetcode.com/problems/divide-two-integers/description/

/*
Approach:
- This is a brute-force simulation of division using repeated addition.
- Convert `dividend` and `divisor` to positive `long long` to avoid overflow.
- Repeatedly add the divisor to a running sum until the sum exceeds the dividend.
- Count how many times this addition was possible — this becomes the quotient.
- Adjust the final sign of the result using XOR: if signs differ, result is negative.

Why TLE:
- For large inputs (e.g., dividend = 2^31, divisor = 1), it may take billions of additions.
- Hence, time complexity is O(n) in worst case — not efficient for large inputs.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Convert to long long to avoid overflow
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long quotient = 0, sum = 0;

        while (sum + b <= a) {
            sum += b;
            quotient++;
        }

        // Restore sign
        if ((dividend < 0) ^ (divisor < 0)) {
            quotient = -quotient;
        }

        return (int)quotient;
    }
};


/*
Approach:
- Use bit manipulation to speed up the division process.
- Like long division, we subtract the largest possible multiple of divisor (using left shifts).
- For each iteration:
   1. Find the largest power `cnt` such that (divisor << cnt) <= dividend.
   2. Subtract (divisor << cnt) from dividend.
   3. Add (1 << cnt) to the answer.
- Continue until what's left of dividend is smaller than divisor.
- Convert dividend and divisor to `long` to safely handle INT_MIN.
- Special cases:
    - Handle INT_MIN / -1 overflow case → return INT_MAX.
    - Use XOR to apply the correct sign to the final result.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
       if(divisor == dividend){
            return 1;
        }

        if(divisor == 1){
            return dividend;
        }

        if(divisor == -1){
            if(dividend == INT_MIN){
                return INT_MAX;
            }
            return -1 * dividend;
        }
        
        long n = (long)dividend;
        long d = (long)divisor;

        if (n < 0) n = -n;
        if (d < 0) d = -d;

        int ans = 0;

        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt++;
            }
            ans += 1 << cnt;
            n -= d << cnt;
        }

        if ((dividend < 0) ^ (divisor < 0)) {
            ans = -ans;
        }

        return ans;
    }
};