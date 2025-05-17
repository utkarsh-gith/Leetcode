class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy = prices[0];
        int sell = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            if (buy > prices[i])
            {
                buy = prices[i];
            }
            sell = max(sell, prices[i] - buy);
        }

        return sell;
    }
};

// OR

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> buy(n, 0);
        vector<int> sell(n, 0);

        buy[0] = prices[0];
        sell[n - 1] = prices[n - 1];

        for (int i = 1; i < n - 1; i++)
        {
            buy[i] = min(buy[i - 1], prices[i]);
            sell[n - i - 1] = max(sell[n - i], prices[n - i - 1]);
        }

        int mProfit = 0;
        for (int i = 0; i < n - 1; i++)
        {
            mProfit = max(mProfit, sell[i + 1] - buy[i]);
        }

        return mProfit;
    }
};