// Using Stack

class Solution {
public:
    string clearDigits(string s) {
        
        stack<char> clear;
        int n = s.length();
        for(int i = 0;i < n;i++){
            
            if(clear.empty()){
                clear.push(s[i]);
                continue;
            }
            if(isdigit(s[i]) && isalpha(clear.top())){
                clear.pop();
            }else{
                clear.push(s[i]);
            }
        }

        s = "";
        while(!clear.empty()){
            s = clear.top() + s;
            clear.pop();
        }
        return s;
    }
};

// OR

