class Solution {
public:
    bool notVowel(char c){
        c = tolower(c);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return false;
        }
        return true;
    }
    string reverseVowels(string s) {
        int n = s.length();
        int i = 0;
        int j = n - 1;

        while(i < j){
            while(i < n && notVowel(s[i])){
                i++;
            }
            while(j >= 0 && notVowel(s[j])){
                j--;
            }
            if(i < j){
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }

        return s;
    }
};