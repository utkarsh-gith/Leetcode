class Solution
{
public:
    void combination(vector<vector<int>> &res, vector<int> &ans, vector<int> &hash, vector<int> &nums)
    {
        if (ans.size() == hash.size())
        {
            res.push_back(ans);
            return;
        }

        for (int i = 0; i < hash.size(); i++)
        {
            if (hash[i] != 0)
            {
                continue;
            }
            hash[i] = 1;
            ans.push_back(nums[i]);
            combination(res, ans, hash, nums);
            ans.pop_back();
            hash[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> ans;
        vector<int> hash(nums.size(), 0);
        combination(res, ans, hash, nums);
        return res;
    }
};