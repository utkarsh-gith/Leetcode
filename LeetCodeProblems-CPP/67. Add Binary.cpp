//top code is better than the bottom one

class Solution {
public:
    string addBinary(string a, string b) {
        
        int i = 0;
        int sum = 0, carry = 0, temp = 0;;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int n = a.size(), m = b.size();
        int k = min(m,n);
        string res;

        while(i < k){
            
            temp = a[i] - '0' + b[i] - '0' + carry;
            sum = temp % 2;
            carry = temp / 2;
            res += to_string(sum);
            i++;
        }

        while(i < n){
            temp = a[i] - '0' + carry;
            sum = temp % 2;
            carry = temp / 2;
            res += to_string(sum);
            i++;
        }

        while(i < m){
            temp = b[i] - '0' + carry;
            sum = temp % 2;
            carry = temp / 2;
            res += to_string(sum);
            i++;
        }

        if(carry){
            res += '1';
        }

        reverse(res.begin(),res.end());

        return res;

    }
};

//or


class Solution {
public:

    string add(string a, string b, int n,int m){
        
        int c = 0;
        int i = n, j = m, k = 0;
        string s;;

        while(j>=0){
            if(a[i] == '0' && b[j] == '0'){
                if(c == 1){
                    s += '1';
                    c = 0;
                }
                else{
                    s += '0';
                }
            }
            else if(a[i] == '1' && b[j] == '1'){
                if(c == 1){
                    s += '1';
                }
                else{
                    s += '0';
                    c = 1;
                }
            }
            else{
                if(c == 1){
                    s += '0';
                    c = 1;
                }
                else{
                    s += '1';
                }
            }

            i--;
            j--;

        }

        while(c == 1){
            if(i >= 0){
                if(a[i] == '0'){
                    s += '1';
                    c = 0;
                }
                else{
                    s += '0';
                }
                i--;
            }
            else{
                s += '1';
                c = 0;
            }
            
        }

        while(i>=0){
            s += a[i];
            i--;
        }

        reverse(s.begin(),s.end());

        return s;
    }
    string addBinary(string a, string b) {
        
        int n = a.size() - 1;
        int m = b.size() - 1;
        string s;

        if(n<m){
            s = add(b,a,m,n);
        }
        else{
            s = add(a,b,n,m);
        }

        return s;

    }
};