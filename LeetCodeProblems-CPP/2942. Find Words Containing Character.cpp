class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        
        vector<int> ans;
        int i = 0;

        for(auto word : words){
            for(auto c : word){
                if(c == x){
                    ans.push_back(i);
                    break;
                }
            }
            i++;
        }

        return ans;
    }
};