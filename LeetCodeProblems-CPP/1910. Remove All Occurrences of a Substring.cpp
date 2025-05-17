class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        while(s.size() != 0 && s.find(part) < s.size()){
            s.erase(s.find(part),part.length());
        }
        return s;
    }
};

//OR

class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        int n = part.length();
        int i = 0;

        while(s.length() >= n){

            bool found = true;

            for(int j=0;j<n;j++){
                if(s[i+j] != part[j]){
                    found = false;
                    break;
                } 
            }
            if(found){
                s.erase(i,n);
                i = 0;
            }
            else{
                i++;
            }
            if (i >= s.length()) {
                break;
            }
        }
        return s;
    }
};