class Solution
{
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();

        int res = 0;
        if (m % 2 == 1)
        {
            for (int num : nums1)
            {
                res ^= num;
            }
        }
        if (n % 2 == 1)
        {
            for (int num : nums2)
            {
                res ^= num;
            }
        }

        return res;
    }
};