class Solution
{
public:
    int tribonacci(int n)
    {
        vector<int> series(3, 1);
        series[0] = 0;

        if (n <= 2)
        {
            return series[n];
        }

        for (int i = 3; i <= n; i++)
        {
            int x = series[0] + series[1] + series[2];
            series[0] = series[1];
            series[1] = series[2];
            series[2] = x;
        }

        return series[2];
    }
};