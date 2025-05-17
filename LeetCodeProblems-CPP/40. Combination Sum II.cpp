class Solution
{
public:
    void generateCombination(vector<vector<int>> &res, vector<int> &inter, vector<int> &candidates, int start, int target)
    {
        if (target == 0)
        {
            res.push_back(inter);
            return;
        }

        for (int i = start; i < candidates.size(); i++)
        {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            inter.push_back(candidates[i]);
            generateCombination(res, inter, candidates, i + 1, target - candidates[i]);
            inter.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> inter;
        generateCombination(res, inter, candidates, 0, target);
        return res;
    }
};

// OR

class Solution
{
public:
    void generateCombination(vector<vector<int>> &res, vector<int> &inter, vector<int> &candidates, int index, int target)
    {
        if (target == 0)
        {
            res.push_back(inter);
            return;
        }

        if (target < 0 || index >= candidates.size())
        {
            return;
        }

        inter.push_back(candidates[index]);
        generateCombination(res, inter, candidates, index + 1, target - candidates[index]);
        inter.pop_back();

        while (index + 1 < candidates.size() && candidates[index] == candidates[index + 1])
        {
            index++;
        }
        generateCombination(res, inter, candidates, index + 1, target);
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> inter;
        generateCombination(res, inter, candidates, 0, target);
        return res;
    }
};