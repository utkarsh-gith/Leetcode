class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        
        int j = 0;
        string t = "";

        for(int i = 0;i < s.length(); i++){

            if(j < spaces.size() && spaces[j] == i){
                t += ' ';
                j++;
            }
            t += s[i];

        }

        return t;
    }
};