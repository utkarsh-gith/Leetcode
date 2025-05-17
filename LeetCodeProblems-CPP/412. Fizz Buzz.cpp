class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<string> res;

        for(int a = 1;a <= n;a++){
            if(a % 3 == 0 && a % 5 == 0){
                res.push_back("FizzBuzz");
            }else if(a % 3 == 0){
                res.push_back("Fizz");
            }else if(a % 5 == 0){
                res.push_back("Buzz");
            }else{
                res.push_back(to_string(a));
            }
        }

        return res;
    }
};