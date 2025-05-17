class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        map<int, int> count;
        int i;
        for (i = nums.size() - 1; i >= 0; i--)
        {
            if (count[nums[i]] > 0)
            {
                break;
            }
            count[nums[i]]++;
        }
        return (int)ceil((i + 1) / 3.0);
    }
};

// OR

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int dup = 0;
        map<int, int> count;
        for (int num : nums)
        {
            count[num]++;
            if (count[num] > 1)
            {
                dup++;
            }
        }

        reverse(nums.begin(), nums.end());

        int opr = 0;
        while (dup != 0)
        {
            int m = nums.size();
            int n = min(m, 3);
            for (int i = 0; i < n; i++)
            {
                if (count[nums.back()] > 1)
                {
                    dup--;
                }
                count[nums.back()]--;
                nums.pop_back();
            }
            opr++;
        }

        return opr;
    }
};