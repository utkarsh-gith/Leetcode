class Solution {
public:
    int maxDepth(string s) {
        
        int depth = 0;
        int open = 0;

        for(char c : s){
            if(c == '('){
                open++;
                depth = max(depth,open);
            }else if(c == ')'){
                open--;
            }
        }

        return depth;
    }
};