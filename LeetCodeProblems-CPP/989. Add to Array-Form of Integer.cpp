class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        int n = num.size();

        for(int i=n-1;i>=0;i--){
            if(k != 0){
                k = k + num[i];
                num[i] = k%10;
                k /= 10;
            }
        }
        
        while(k != 0){
            num.insert(num.begin(),k%10);
            k /= 10;
        }

        return num;
    }
};

//OR

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        int n = num.size();
        int sum = 0;

        for(int i=n-1;i>=0;i--){
            sum = num[i] + (k%10) + sum;
            num[i] = sum%10;
            sum /= 10;
            k /= 10;
        }
        while(sum != 0){
            sum = (k%10) + sum;
            num.insert(num.begin(),sum % 10);
            sum /= 10;
            k /= 10;
        }
        while(k != 0){
            num.insert(num.begin(),k%10);
            k /= 10;
        }

        return num;
    }
};