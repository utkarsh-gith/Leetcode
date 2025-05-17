class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        long long maxVal = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    long long n1 = nums[i] - nums[j];
                    long long n2 = nums[k];
                    maxVal = max(maxVal, n1 * n2);
                }
            }
        }

        return maxVal;
    }
};