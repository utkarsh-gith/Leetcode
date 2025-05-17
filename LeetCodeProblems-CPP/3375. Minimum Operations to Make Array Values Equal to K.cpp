class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        std::sort(nums.begin(), nums.end());
        if (k > nums[0])
            return -1;

        int res = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] != nums[i])
            {
                res++;
            }
        }
        if (k != nums[0])
        {
            res++;
        }
        return res;
    }
};

// OR

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        map<int, bool> check;
        int opr = 0;
        for (int num : nums)
        {
            if (num < k)
            {
                return -1;
            }
            if (num > k)
            {
                if (check[num] == false)
                {
                    opr++;
                    check[num] = true;
                }
            }
        }
        return opr;
    }
};