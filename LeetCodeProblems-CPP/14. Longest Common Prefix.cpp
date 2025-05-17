class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {

        int n = strs.size();
        int min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (min > strs[i].length())
            {
                min = strs[i].length();
            }
        }

        if (!min)
        {
            return "";
        }

        int i = 0;
        string str = "";
        while (i < min)
        {
            char c = strs[0][i];
            int j = 1;
            for (j = 1; j < n; j++)
            {
                if (c != strs[j][i])
                {
                    break;
                }
            }
            if (j != n)
            {
                break;
            }
            str.push_back(c);
            i++;
        }

        return str;
    }
};

// OR

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {

        string ans = "";

        for (int i = 0; i < strs[0].size(); i++)
        {

            char ch = strs[0][i];
            bool match = true;

            for (int j = 0; j < strs.size(); j++)
            {

                if (strs[j].size() < i || strs[j][i] != ch)
                {
                    match = false;
                    break;
                }
            }

            if (match == false)
            {
                break;
            }
            ans += ch;
        }

        return ans;
    }
};