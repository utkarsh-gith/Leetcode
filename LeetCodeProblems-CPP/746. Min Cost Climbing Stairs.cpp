// Recursion (TLE)

class Solution
{
    int minCost(vector<int> &cost, int n, int p)
    {
        if (p == n - 1 || p == n - 2)
        {
            return cost[p];
        }

        return cost[p] + min(minCost(cost, n, p + 1), minCost(cost, n, p + 2));
    }

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        return min(minCost(cost, cost.size(), 0), minCost(cost, cost.size(), 1));
    }
};

// DP (Recursion + Memorisation)

class Solution
{
    int minCost(vector<int> &cost, int n, vector<int> &tCost)
    {
        if (n == 0 || n == 1)
        {
            return cost[n];
        }

        if (tCost[n] != -1)
        {
            return tCost[n];
        }
        tCost[n] = cost[n] + min(minCost(cost, n - 1, tCost), minCost(cost, n - 2, tCost));
        return tCost[n];
    }

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> tCost(n + 1, -1);
        return min(minCost(cost, n - 1, tCost), minCost(cost, n - 2, tCost));
    }
};

// DP (Tabulation)

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, -1);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; i++)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        dp[n] = min(dp[n - 1], dp[n - 2]);
        return dp[n];
    }
};

// OR

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int n1 = cost[0];
        int n2 = cost[1];

        for (int i = 2; i < n; i++)
        {
            int n3 = cost[i] + min(n1, n2);
            swap(n3, n2);
            swap(n3, n1);
        }

        return min(n1, n2);
    }
};