// Note: all characters in the substring must be same

class Solution {
public:
    int maximumLength(string s) {
        
        int n = s.length();

        for(int len = n - 2;len > 0;len--){

            map<string,int> check;
            string c;

            for(int i = 0;i <= n - len;i++){
                c = s.substr(i,len);
                sort(c.begin(),c.end());
                if(c[0] == c[len - 1]){
                    check[c]++;
                }
            }

            for(auto ch : check){
                if(ch.second >= 3){
                    return len;
                }
            }

        }

        return -1;
    }
};

//

class Solution {
public:
    int getMin(int a, int b, int c){
        if(a <= b && b <= c){
            return 0;
        }
        if(b <= c){
            return 1;
        }
        return 2;
    }
    int maximumLength(string s) {
        
        int n = s.length();

        vector<vector<int>> freq(26,vector<int>(3,-1));
    
        char last = '1';
        int window = 0;

        for(char c : s){
            
            int idx = c - 'a';
            window = c == last ? window + 1 : 1;
            last = c;

            int minLen = getMin(freq[idx][0], freq[idx][1], freq[idx][2]);

            if(freq[idx][minLen] < window){
                freq[idx][minLen] = window;
            }

        }

        int maxLen = -1;
        for(int i = 0;i < 26;i++){
            maxLen = max(maxLen, min(freq[i][0], min(freq[i][1], freq[i][2])));
        }
        return maxLen;
    }
};