class Solution {
public:
    int bitwiseComplement(int n) {
        
        int sum=0,r=0;
        do
        {
            int res=(n&1);
            sum=sum-(res-1)*pow(2,r++);
            n=n>>1;
        }while(n);
        return sum;
    }
};