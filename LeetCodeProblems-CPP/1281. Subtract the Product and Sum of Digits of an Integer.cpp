class Solution {
public:
    int subtractProductAndSum(int n) {
        
        int s=0;
        int p=1;
        while(n!=0)
        {
            int temp=n%10;
            s=s+temp;
            p=p*temp;
            n=n/10;
        }
        int a=p-s;
        return a;
    }
    
};