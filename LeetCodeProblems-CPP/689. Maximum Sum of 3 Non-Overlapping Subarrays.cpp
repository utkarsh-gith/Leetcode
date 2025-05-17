class Solution
{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {

        int n = nums.size();
        vector<int> sumArr(n - k + 1, 0);

        int sum = 0;
        for (int i = 0; i < k; i++)
            sum += nums[i];
        sumArr[0] = sum;
        for (int i = k; i < n; i++)
        {
            sum += nums[i] - nums[i - k];
            sumArr[i - k + 1] = sum;
        }

        vector<int> left(n - k + 1, 0), right(n - k + 1, 0);
        left[0] = 0;
        for (int i = 1; i < sumArr.size(); i++)
        {
            left[i] = sumArr[i] > sumArr[left[i - 1]] ? i : left[i - 1];
        }
        right[sumArr.size() - 1] = sumArr.size() - 1;
        for (int i = sumArr.size() - 2; i >= 0; i--)
        {
            right[i] = sumArr[i] >= sumArr[right[i + 1]] ? i : right[i + 1];
        }

        vector<int> ans(3, -1);
        int maxSum = 0;
        for (int j = k; j < sumArr.size() - k; j++)
        {
            int l = left[j - k];
            int r = right[j + k];
            int total = sumArr[l] + sumArr[j] + sumArr[r];
            if (total > maxSum)
            {
                maxSum = total;
                ans = {l, j, r};
            }
        }

        return ans;
    }
};