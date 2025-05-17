class Solution {
public:
    string largestOddNumber(string num) {
        
        int n = num.length() - 1;
        string s = "";
        
        while(n >= 0){
            if((num[n] - '0') % 2 != 0){
                for(int j = 0;j <= n;j++){
                    s += num[j];
                }
                break;
            }
            n--;
        }

        return s;
    }
};