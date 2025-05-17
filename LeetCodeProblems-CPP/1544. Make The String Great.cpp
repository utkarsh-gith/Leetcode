class Solution {
public:
    string makeGood(string s) {
        
        stack<char> check;
        int n = s.length();

        for(char c : s){
            if(!check.empty()){
                if((c != check.top()) && (tolower(c) == tolower(check.top()))){
                    check.pop();
                }else{
                    check.push(c);
                }
            }else{
                check.push(c);
            }
        }

        s = "";
        while(!check.empty()){
            s = check.top() + s;
            check.pop();
        }

        return s;

    }
};