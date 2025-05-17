class Solution
{
public:
    const int mod = 1000000007;
    int countWays(vector<int> &dp, int len, int zero, int one)
    {
        if (len == 0)
        {
            return 1;
        }
        if (len < 0)
        {
            return 0;
        }
        if (dp[len] != -1)
        {
            return dp[len];
        }

        long long waysFromZero = countWays(dp, len - zero, zero, one) % mod;
        long long waysFromOne = countWays(dp, len - one, zero, one) % mod;

        dp[len] = (waysFromZero + waysFromOne) % mod;
        return dp[len];
    }
    int countGoodStrings(int low, int high, int zero, int one)
    {
        vector<int> dp(high + 1, -1);
        int ways = 0;
        for (int len = low; len <= high; len++)
        {
            ways = (ways + countWays(dp, len, zero, one)) % mod;
        }

        return ways;
    }
};