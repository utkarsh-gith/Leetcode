// TC -> O(n)
class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int pos = 0, neg = 0;
        for (int num : nums)
        {
            if (num > 0)
            {
                pos++;
            }
            else if (num < 0)
            {
                neg++;
            }
        }
        return max(pos, neg);
    }
};

// TC -> O(log(n))
class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, h = n - 1;
        int pos = n, neg = -1;

        while (l <= h)
        {
            int m = l + (h - l) / 2;

            if (nums[m] < 0)
            {
                neg = m;
                l = m + 1;
            }
            else if (nums[m] > 0)
            {
                pos = m;
                h = m - 1;
            }
            else
            {
                neg = m, pos = m;
                while (neg >= 0 && nums[neg] == 0)
                    neg--;
                while (pos < n && nums[pos] == 0)
                    pos++;
                break;
            }
        }

        return max(neg + 1, n - pos);
    }
};