// you can also take res as long long int and then check if it is greater 
// than int_max

class Solution {
public:
    int myAtoi(string s) {
        
        int n = s.length();
        int i = 0;
        bool pos = true;
        int res = 0;

        while(i < n && s[i] == ' '){
            i++;
        }

        if(i < n){
            if(s[i] == '-'){
                pos = false;
                i++;
            }
            else if(s[i] == '+'){
                i++;
            }
        }

        while(i < n && isdigit(s[i])){
            int digit = s[i] - '0';
            if(res > INT_MAX/10 || (res == INT_MAX/10 && digit > INT_MAX%10)){
                return pos ? INT_MAX : INT_MIN;
            }
            res = res*10 + digit;
            i++;
        }

        return pos ? res : -res;
    }
};