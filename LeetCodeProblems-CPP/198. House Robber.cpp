// Recursion (TLE)

class Solution
{
public:
    int solve(vector<int> &nums, int n)
    {
        if (n < 0)
        {
            return 0;
        }
        if (n == 0)
        {
            return nums[0];
        }

        int incl = solve(nums, n - 2) + nums[n];
        int excl = solve(nums, n - 1);

        return max(incl, excl);
    }
    int rob(vector<int> &nums)
    {
        return solve(nums, nums.size() - 1);
    }
};

// Recursion + Memoisation

class Solution
{
public:
    int solve(vector<int> &nums, int n, vector<int> &dp)
    {
        if (n < 0)
        {
            return 0;
        }
        if (n == 0)
        {
            return nums[0];
        }

        if (dp[n] != -1)
        {
            return dp[n];
        }
        int incl = solve(nums, n - 2, dp) + nums[n];
        int excl = solve(nums, n - 1, dp);

        dp[n] = max(incl, excl);
        return dp[n];
    }
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size(), -1);
        return solve(nums, nums.size() - 1, dp);
    }
};

// Tabulation

class Solution
{
public:
    int rob(vector<int> &nums)
    {

        int n = nums.size();

        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++)
        {
            int incl = dp[i - 2] + nums[i];
            int excl = dp[i - 1];
            dp[i] = max(incl, excl);
        }

        return dp[n - 1];
    }
};

// OR

class Solution
{
public:
    int rob(vector<int> &nums)
    {

        int n = nums.size();

        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        int n1 = nums[0];
        int n2 = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++)
        {
            int n3 = max(n1 + nums[i], n2);
            n1 = n2;
            n2 = n3;
        }

        return n2;
    }
};

// OR

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
        {
            return nums[0];
        }

        int n1 = 0;
        int n2 = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            int n3 = max(nums[i] + n1, n2);
            n1 = n2;
            n2 = n3;
        }

        return n2;
    }
};