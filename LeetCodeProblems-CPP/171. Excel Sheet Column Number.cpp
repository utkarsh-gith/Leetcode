class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int n = columnTitle.length();
        int i = 0;
        int res = 0;

        while(i < n){
            int temp = columnTitle[i] - 'A' + 1;
            res = res * 26 + temp;
            i++;
        }

        return res;
    }
};