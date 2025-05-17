class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        map<int, int> count;
        for (int num : nums)
        {
            if (count[num] == 1)
            {
                count[num] = 0;
            }
            else
            {
                count[num] = 1;
            }
        }
        for (auto c : count)
        {
            if (c.second == 1)
            {
                return false;
            }
        }
        return true;
    }
};

// OR

class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 2)
        {
            if (nums[i] != nums[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};