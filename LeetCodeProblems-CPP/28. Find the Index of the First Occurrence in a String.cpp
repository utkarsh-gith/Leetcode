class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = haystack.find(needle);
        return index;
    }
};

// OR

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n = haystack.length();
        int m = needle.length();

        if(n < m){
            return -1;
        }

        for(int i = 0;i < n - m + 1;i++){
            string s = "";
            for(int j = i;j < m + i;j++){
                s += haystack[j];
            }
            if(s == needle){
                return i;
            }
        }

        return -1;
    }
};