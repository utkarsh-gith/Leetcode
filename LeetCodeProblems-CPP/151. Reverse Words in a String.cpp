class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.length() - 1;
        string t = "";

        while(n >= 0){

            while(n >= 0 && isspace(s[n])){
                n--;
            }

            string m = "";

            while(n >= 0){
                if(!isalpha(s[n]) && !isdigit(s[n])){
                    break;
                }
                m = s[n] + m;
                n--;
            }

            if(!m.empty()){
                t = t + m + " ";
            }
            
            n--;
        }

        if(!t.empty()){
            t.pop_back();
        }

        return t;

    }
};