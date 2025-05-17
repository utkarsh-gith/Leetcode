class Solution
{
public:
    void opener(vector<string> &result, string output, int open, int close, int n)
    {
        if (open == n)
        {
            return;
        }

        output += "(";
        opener(result, output, open + 1, close, n);
        closer(result, output, open + 1, close, n);
    }
    void closer(vector<string> &result, string output, int open, int close, int n)
    {
        if (close == n)
        {
            result.push_back(output);
            return;
        }

        if (open <= close)
        {
            return;
        }

        output += ")";
        opener(result, output, open, close + 1, n);
        closer(result, output, open, close + 1, n);
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        opener(result, "", 0, 0, n);
        return result;
    }
};

// OR (Backtracking)

class Solution
{
public:
    void generateParenthesUtil(vector<string> &res, string &s, int open, int close)
    {
        if (open == 0 && close == 0)
        {
            res.push_back(s);
            return;
        }

        if (open > 0)
        {
            s.push_back('(');
            generateParenthesUtil(res, s, open - 1, close);
            s.pop_back();
        }
        if (close > open)
        {
            s.push_back(')');
            generateParenthesUtil(res, s, open, close - 1);
            s.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        string s = "";
        generateParenthesUtil(result, s, n, n);
        return result;
    }
};