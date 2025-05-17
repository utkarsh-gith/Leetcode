class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        priority_queue<int> pile;
        long long sum = 0;

        for(int gif : gifts){
            pile.push(gif);
            sum += gif;
        }

        for(int i = 0;i < k;i++){
            int n = pile.top();
            sum -= (n - sqrt(n));
            pile.pop();
            pile.push(sqrt(n));
        }

        return sum;
    }
};