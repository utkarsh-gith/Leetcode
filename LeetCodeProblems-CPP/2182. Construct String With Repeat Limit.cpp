class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        
        map<char,int> freq;

        for(char c : s){
            freq[c]++;
        }

        priority_queue<pair<char,int>> pq;
        for(auto f : freq){
            pq.push({f.first, f.second});
        }

        int limit = repeatLimit;
        string ans;
        while(!pq.empty()){

            pair<char,int> temp = pq.top();
            pq.pop();

            ans += temp.first;
            temp.second--;
            limit--;

            if(temp.second == 0){
                limit = repeatLimit;
                continue;
            }
            if(limit == 0){
                if(pq.empty()){
                    break;
                }
                pair<char,int> temp1 = pq.top();
                pq.pop();

                ans += temp1.first;
                temp1.second--;

                if(temp1.second != 0){
                    pq.push(temp1);
                }
                limit = repeatLimit;
          
            }
            pq.push(temp);
        }

        return ans;
    }
};