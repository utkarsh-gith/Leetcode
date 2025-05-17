class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        vector<int> score;

        for(auto c : operations){
            if(isdigit(c[0]) || c[0] == '-'){
                score.push_back(stoi(c));
            }else if(c == "+"){
                int n = score.size();
                score.push_back(score[n-1] + score[n-2]);
            }else if(c == "D"){
                score.push_back(score.back() * 2);
            }else if(c == "C"){
                score.pop_back();
            }
        }

        int total = 0;

        for(auto t : score){
            total += t;
        }

        return total;

    }
};