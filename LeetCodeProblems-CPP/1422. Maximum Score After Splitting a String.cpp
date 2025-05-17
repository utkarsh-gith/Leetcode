class Solution
{
public:
    int maxScore(string s)
    {

        int maxOne = 0;
        int maxZero = 0;
        int maxSum = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
            {
                maxOne++;
            }
        }

        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == '0')
            {
                maxZero++;
            }
            else
            {
                maxOne--;
            }
            maxSum = max(maxSum, maxZero + maxOne);
        }

        return maxSum;
    }
};