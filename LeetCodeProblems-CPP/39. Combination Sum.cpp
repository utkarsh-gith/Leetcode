class Solution
{
public:
    void sumFinder(vector<vector<int>> &res, vector<int> &output, vector<int> &candidates, int target, int index)
    {
        if (target == 0)
        {
            res.push_back(output);
            return;
        }
        if (target < 0 || index >= candidates.size())
        {
            return;
        }

        output.push_back(candidates[index]);
        sumFinder(res, output, candidates, target - candidates[index], index);
        output.pop_back();

        sumFinder(res, output, candidates, target, index + 1);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> output;
        sumFinder(result, output, candidates, target, 0);
        return result;
    }
};