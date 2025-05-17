class Solution {
public:
    int compress(vector<char>& chars) {
        
        int n = chars.size();
        int index = 0;
        int i = 0;

        while(i<n){
            
            int j = i + 1;
            
            while(j<n && chars[i] == chars[j]){
                j++;
            }

            int count = j - i;
            chars[index++] = chars[i];

            if(count > 1){
                string c = to_string(count);
                for(char ch:c){
                    chars[index++] = ch;
                }
            }

            i=j;

        }

        return index;
    }
};