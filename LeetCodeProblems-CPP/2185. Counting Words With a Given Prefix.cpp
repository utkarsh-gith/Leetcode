class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int count = 0;
        int n = pref.length();

        for (string word : words)
        {

            if (n > word.length())
            {
                continue;
            }

            if (word.substr(0, n) == pref)
            {
                count++;
            }
            // int i = 0;
            // while(i < pref.length() && pref[i] == word[i]){
            //     i++;
            // }
            // if(i == pref.length()){
            //     count++;
            // }
        }

        return count;
    }
};