class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        long long sum = 0;
        for (int num : nums)
        {
            sum += num;
        }

        int ways = 0;
        long long left = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            left += nums[i];
            long long right = sum - left;
            if (left >= right)
            {
                ways++;
            }
        }

        return ways;
    }
};

// OR

class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {

        int n = nums.size();
        vector<long long> left(n - 1, 0);
        vector<long long> right(n - 1, 0);

        for (int i = 0; i < n - 1; i++)
        {
            left[i] = nums[i];
            right[n - 2 - i] = nums[n - 1 - i];
            if (i > 0)
            {
                left[i] += left[i - 1];
                right[n - 2 - i] += right[n - 1 - i];
            }
        }

        int count = 0;
        for (int i = 0; i < left.size(); i++)
        {
            if (left[i] >= right[i])
            {
                count++;
            }
        }

        return count;
    }
};