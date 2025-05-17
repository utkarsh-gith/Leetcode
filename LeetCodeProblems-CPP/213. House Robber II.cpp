// Consider from 0 to n-1 as an answer and 1 to n as another answer
// return max of both the answers

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
        {
            return nums[0];
        }

        int n1 = nums[0];
        int n2 = max(nums[0], nums[1]);

        if (n == 2)
        {
            return max(n1, n2);
        }

        for (int i = 2; i < n - 1; i++)
        {
            int n3 = max(n2, n1 + nums[i]);
            n1 = n2;
            n2 = n3;
        }

        int ans = n2;

        n1 = nums[1];
        n2 = max(nums[1], nums[2]);

        for (int i = 3; i < n; i++)
        {
            int n3 = max(n2, n1 + nums[i]);
            n1 = n2;
            n2 = n3;
        }

        return max(ans, n2);
    }
};