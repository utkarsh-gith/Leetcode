class Solution
{
public:
    bool check(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {

        int n = words.size();
        vector<int> vowel(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (check(words[i].front()) && check(words[i].back()))
            {
                vowel[i] = 1;
            }
            if (i > 0)
            {
                vowel[i] += vowel[i - 1];
            }
        }

        vector<int> result;

        for (auto query : queries)
        {
            int left = query[0];
            int right = query[1];

            int count = vowel[right];
            if (left > 0)
            {
                count -= vowel[left - 1];
            }
            result.push_back(count);
        }

        return result;
    }
};