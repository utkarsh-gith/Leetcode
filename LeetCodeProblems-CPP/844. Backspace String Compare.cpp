class Solution {
public:

    string backSpaceString(string s){
        
        int n = s.length();
        string t = "";
        int i = 0;

        while(i < n){
            if(s[i] == '#'){
                if(!t.empty()){
                    t.pop_back();
                }
            }else{
                t.push_back(s[i]);
            }
            i++;
        }
        return t;
    }
    bool backspaceCompare(string s, string t) {
        
        string s1 = backSpaceString(s);
        string s2 = backSpaceString(t);
        
        return (s1 == s2);
    }
};