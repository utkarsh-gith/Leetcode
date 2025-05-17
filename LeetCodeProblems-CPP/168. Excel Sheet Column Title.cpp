class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string s;
        while(columnNumber > 0){
            columnNumber--;
            int temp = (columnNumber%26);
            s += temp + 'A';
            columnNumber /= 26;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};