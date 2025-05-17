class Solution
{
public:
    int minimumLength(string s)
    {

        if (s.length() <= 2)
        {
            return s.length();
        }

        // map<char,int> freq;
        vector<int> freq(26, 0);
        int count = s.length();

        for (char c : s)
        {
            freq[c - 'a']++;
            if (freq[c - 'a'] == 3)
            {
                freq[c - 'a'] = 1;
                count -= 2;
            }
        }

        return count;
    }
};