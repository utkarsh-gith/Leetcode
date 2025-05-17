class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        for(int i = 0;i < prices.size(); i++){
            int j = i + 1;
            while(j < prices.size() && prices[j] > prices[i]){
                j++;
            }

            if(j < prices.size()){
                prices[i] -= prices[j];
            }
        }
        return prices;
    }
};

// OR

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        int n = prices.size();
        vector<int> ans(prices);
        stack<int> st;

        for(int i = 0;i < n; i++){
             while(!st.empty() && prices[st.top()] >= prices[i]){
                int index = st.top();
                st.pop();
                ans[index] = prices[index] - prices[i];
            }
            st.push(i);
        }

        return ans;
    }
};