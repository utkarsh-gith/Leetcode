//without stack

class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int open = 0, close = 0;

        for(char c : s){
            if(c == '('){
                open++;
            }
            else{
                if(open > 0){
                    open--;
                }else{
                    close++;
                }
            }
        }

        return open + close;
    }
};

//with stack

class Solution {
public:
    int minAddToMakeValid(string s) {
        
        stack<char> req;

        for(char c : s){
            if(req.empty()){
                req.push(c);
                continue;
            }

            if(c == ')' && req.top() == '('){
                req.pop();
            }else{
                req.push(c);
            }

        }

        return req.size();
    }
};