class Solution {
public:
    int minLength(string s) {
        
        stack<char> check;

        for(char c : s){

            if(check.empty()){
                check.push(c);
                continue;
            }

            if(c == 'B' && check.top() == 'A'){
                check.pop();
            }else if(c == 'D' && check.top() == 'C'){
                check.pop();
            }else{
                check.push(c);
            }
        }

        return check.size();
    }
};