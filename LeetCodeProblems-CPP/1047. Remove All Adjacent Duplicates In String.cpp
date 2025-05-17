//can use stacks as well to solve the problem

//Faster
class Solution {
public:
    string removeDuplicates(string s) {

        string s1;
        int n = s.length();

        for(int i=0;i<n;i++){

            if(!s1.empty() && s1.back() == s[i]){
                s1.pop_back();
            }
            else{
                s1.push_back(s[i]);
            }
        }

        return s1;
    }
};

//Slower

class Solution {
public:
    string removeDuplicates(string s) {

        int i = 0;
        
        while(i<s.length()-1){
            if(s[i] == s[i+1]){
                s.erase(i,2);
                if(i!=0){
                    i--;
                }
            }
            else{
                i++;
            }
            if(s.length() == 0){
                break;
            }
        }

        return s;
    }
};