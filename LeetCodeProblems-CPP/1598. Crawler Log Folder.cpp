class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        int count = 0;
        int n = logs.size();

        for(int i = 0;i < n;i++){
            string s = logs[i];;
            if(s == "../"){
                if(count > 0){
                    count--;
                }
            }else if(s == "./"){
                continue;
            }else{
                count++;
            }
        }

        return count;
    }
};