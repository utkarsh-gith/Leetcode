class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        
        int n = sentence.size();
        int m = searchWord.size();
        int count = 1;
        int i = 0;
        while(i < n){

            int j = 0;
            while(j < m && i < n && (sentence[i] == searchWord[j])){
                i++;
                j++;
            }
            if(j == m){
                return count;
            }else{
                while(i < n && sentence[i] != ' '){
                    i++;
                }
                count ++;
                i++;
            }
        }

        return -1;
    }
};