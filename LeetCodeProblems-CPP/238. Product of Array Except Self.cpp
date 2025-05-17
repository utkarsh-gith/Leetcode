class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int countZero = 0;
        int product = 1;
        for (int num : nums)
        {
            if (num != 0)
            {
                product *= num;
            }
            else
            {
                countZero++;
            }
        }

        vector<int> result;
        if (countZero > 1)
        {
            result.resize(nums.size(), 0);
            return result;
        }

        for (int num : nums)
        {
            if (countZero == 1)
            {
                if (num != 0)
                {
                    result.push_back(0);
                }
                else
                {
                    result.push_back(product);
                }
            }
            else
            {
                result.push_back(product / num);
            }
        }

        return result;
    }
};

// OR

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        const int n = nums.size();
        vector<int> ans(n, 1);

        for (int i = 1; i < n; ++i)
        {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        int suffix = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};