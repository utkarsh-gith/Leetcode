class Solution {
public:
    vector<string> cellsInRange(string s) {
        
        vector<string> res;
        for(char i = s[0]; i <= s[3]; i++){
            for(char j = s[1]; j <= s[4]; j++){
                string cell;
                cell += i;
                cell += j;
                res.push_back(cell);
            }
        }

        return res;
    }
};