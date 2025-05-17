class Solution
{
public:
    void helper(vector<int> &nums, int index, int &sum, int XOR)
    {
        if (index == nums.size())
        {
            sum += XOR;
            return;
        }
        helper(nums, index + 1, sum, XOR ^ nums[index]);
        helper(nums, index + 1, sum, XOR);
    }
    int subsetXORSum(vector<int> &nums)
    {
        int sum = 0;
        int index = 0;
        helper(nums, index, sum, 0);
        return sum;
    }
};