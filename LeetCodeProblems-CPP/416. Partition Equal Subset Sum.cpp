class Solution
{
public:
    bool partitionSum(vector<int> &nums, int idx, int sum, vector<vector<int>> &dp)
    {
        if (sum == 0)
        {
            return true;
        }

        if (idx < 0 || sum < 0)
        {
            return false;
        }

        if (dp[idx][sum] != -1)
        {
            return dp[idx][sum];
        }

        bool ans = partitionSum(nums, idx - 1, sum, dp);
        if (sum - nums[idx] >= 0)
        {
            ans = ans || partitionSum(nums, idx - 1, sum - nums[idx], dp);
        }

        dp[idx][sum] = ans;
        return ans;
    }
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
        {
            return false;
        }
        sum /= 2;

        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));

        return partitionSum(nums, nums.size() - 1, sum, dp);
    }
};

// OR

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total % 2 != 0)
            return false;

        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums)
        {
            for (int i = target; i >= num; i--)
            {
                dp[i] = dp[i] || dp[i - num];
            }
        }

        return dp[target];
    }
};