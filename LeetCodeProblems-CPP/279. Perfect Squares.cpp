class Solution
{
public:
    int findNum(int n, vector<int> &dp)
    {
        if (n == 0)
        {
            return 0;
        }

        if (dp[n] != -1)
        {
            return dp[n];
        }

        int res = n;
        for (int i = 1; i * i <= n; i++)
        {
            int temp = i * i;
            res = min(res, 1 + findNum(n - temp, dp));
        }

        dp[n] = res;
        return dp[n];
    }
    int numSquares(int n)
    {
        vector<int> dp(n + 1, -1);
        return findNum(n, dp);
    }
};

// OR

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            int res = i;
            for (int j = 1; j * j <= i; j++)
            {
                int temp = j * j;
                res = min(res, 1 + dp[i - temp]);
            }
            dp[i] = res;
        }

        return dp[n];
    }
};