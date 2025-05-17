// Recursion (TLE)
class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {

        if (target == 0)
        {
            return 1;
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (target - nums[i] >= 0)
            {
                ans += combinationSum4(nums, target - nums[i]);
            }
        }

        return ans;
    }
};

// Recursion + Memorisation
class Solution
{
public:
    int combination(vector<int> &nums, vector<int> &dp, int target)
    {
        if (target == 0)
        {
            return 1;
        }

        if (dp[target] != -1)
        {
            return dp[target];
        }

        dp[target] = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (target - nums[i] >= 0)
            {
                dp[target] += combination(nums, dp, target - nums[i]);
            }
        }

        return dp[target];
    }
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1, -1);
        return combination(nums, dp, target);
    }
};

// Tabulation
class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i - nums[j] >= 0)
                {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }

        return dp[target];
    }
};