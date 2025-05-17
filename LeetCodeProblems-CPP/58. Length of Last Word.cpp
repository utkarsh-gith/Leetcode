// traverse the string from back

class Solution {
public:
    int lengthOfLastWord(string s) {

        int n = s.length() - 1;
        int i = n;

       while(i>=0){
        if(isalpha(s[i])){
            break;
        }
        i--;
       }

       int j = i;

       while(i>=0){
        if(isspace(s[i])){
            break;
        }
        i--;
       }

       return j-i;
    }
};