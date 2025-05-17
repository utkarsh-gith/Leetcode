class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int cap = 0;

        for(int i = 0;i < word.length(); i++){

            if(isupper(word[i])){
                if(cap == i){
                    cap++;
                }else{
                    return false;
                }
            }else if(islower(word[i]) && cap > 1){
                return false;
            }

        }
        return true;
    }
};