// using extra string

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        
        int n = s.length();
        string ans(n,'0');

        for(int i = 0;i < n;i++){
            ans[indices[i]] = s[i];
        }

        return ans;
    }
};

// without using extra string

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {

        int j;
        for(int i = 0;i < s.length();i++){
            while(indices[i] != i){
                swap(s[i],s[indices[i]]);
                j = indices[i];
                swap(indices[i],indices[j]);
            }
        }

        return s;
    }
};