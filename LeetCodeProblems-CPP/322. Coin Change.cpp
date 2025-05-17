// Recursion (TLE)
class Solution
{
    bool changePossible(vector<int> coins, int amount, int &numCoins)
    {
        if (amount == 0)
        {
            return true;
        }
        if (amount < 0)
        {
            return false;
        }
        for (int i = coins.size() - 1; i >= 0; i--)
        {
            numCoins++;
            amount -= coins[i];
            if (changePossible(coins, amount, numCoins))
            {
                return true;
            }
            amount += coins[i];
            numCoins--;
        }
        return false;
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        sort(coins.begin(), coins.end());
        int numCoins = 0;
        return changePossible(coins, amount, numCoins) ? numCoins : -1;
    }
};

// Other Recursion
class Solution
{
public:
    int recSol(vector<int> &coins, int amount)
    {
        if (amount == 0)
        {
            return 0;
        }
        if (amount < 0)
        {
            return INT_MAX;
        }

        int numCoins = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int ans = recSol(coins, amount - coins[i]);
            if (ans != INT_MAX)
            {
                numCoins = min(numCoins, ans + 1);
            }
        }

        return numCoins;
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int numCoins = recSol(coins, amount);
        return numCoins == INT_MAX ? -1 : numCoins;
    }
};

// Recursion + Memorisation
class Solution
{
public:
    int solution(vector<int> &coins, int amount, vector<int> &mem)
    {
        if (amount == 0)
        {
            return 0;
        }
        if (amount < 0)
        {
            return INT_MAX;
        }

        if (mem[amount] != -1)
        {
            return mem[amount];
        }
        int numCoins = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int ans = solution(coins, amount - coins[i], mem);
            if (ans != INT_MAX)
            {
                numCoins = min(numCoins, ans + 1);
            }
        }

        mem[amount] = numCoins;

        return numCoins;
    }
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> mem(amount + 1, -1);
        int numCoins = solution(coins, amount, mem);
        return numCoins == INT_MAX ? -1 : numCoins;
    }
};

// Tabulation
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX)
                {
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};