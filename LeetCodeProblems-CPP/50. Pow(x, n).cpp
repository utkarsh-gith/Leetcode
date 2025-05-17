class Solution {
public:

    double Power(double x, unsigned int n){

        if(n == 0){
            return 1;
        }
        if(n == 1){
            return x;
        }

        double half = Power(x,n/2);

        if(n%2 == 0)
            return half * half;
        else
            return half * half * x;

    }
    double myPow(double x, int n) {

        unsigned int m;
        if(n<0){
            x = 1/x;
            m = -(double(n));
        }
        else{
            m = n;
        }

        return Power(x,m);
    }
};