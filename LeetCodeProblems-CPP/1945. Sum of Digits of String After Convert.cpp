class Solution {
public:
    int getLucky(string s, int k) {

        int sum = 0;
        for(char c : s){
            int temp = c - 'a' + 1;
            while(temp > 0){
                sum += (temp % 10);
                temp /= 10;
            }
        }

        k--;

        while(k > 0){
            int temp = 0;
            while(sum > 0){
                temp += (sum % 10);
                sum /= 10;
            }
            sum = temp;
            k--;
        }
        
        return sum;
    }
};