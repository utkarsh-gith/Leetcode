class Solution {
public:
    int longestValidParentheses(string s) {
        
        int left = 0;
        int right = 0;
        int longest = 0;

        for(char c : s){
            if(c == '('){
                left++;
            }else{
                right++;
            }
            if(left == right){
                longest = max(longest, 2 * left);
            }else if(right > left){
                left = 0;
                right = 0;
            }
        }

        left = 0;
        right  = 0;

        for(int i = s.length() - 1;i >= 0;i--){
            char c = s[i];
            if(c == '('){
                left++;
            }else{
                right++;
            }
            if(left == right){
                longest = max(longest, 2 * left);
            }else if(right < left){
                left = 0;
                right = 0;
            }
        }

        return longest;
    }
};