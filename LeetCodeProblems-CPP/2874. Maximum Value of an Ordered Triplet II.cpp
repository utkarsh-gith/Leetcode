class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> prefix(n, 0);
        prefix[0] = nums[0];

        vector<int> suffix(n, 0);
        suffix[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++)
        {
            prefix[i] = max(nums[i], prefix[i - 1]);
            suffix[n - i - 1] = max(nums[n - i - 1], suffix[n - i]);
        }

        long long ans = 0;
        for (int i = 1; i < n - 1; i++)
        {
            long long a = prefix[i - 1] - nums[i];
            long long b = suffix[i + 1];
            ans = max(ans, a * b);
        }

        return ans;
    }
};

// OR

class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        long long highest = max(nums[0], nums[1]);
        long long difference = nums[0] - nums[1];
        long long answer = 0;

        for (int i = 2; i < nums.size(); i++)
        {
            answer = max(answer, difference * nums[i]);
            difference = max(difference, highest - nums[i]);
            highest = max(highest, (long long)nums[i]);
        }

        return answer;
    }
};