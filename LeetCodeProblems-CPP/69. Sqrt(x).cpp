class Solution {
public:
    int mySqrt(int x) {
        long int l=0,h=x,m,n;
        n=h;
        if(x==1)
            return 1;
        while(l<=h)
        {
            m=(l+h)/2;
            if(m*m==x)
                return m;
            else if(m*m>x)
                h=m-1;
            else
                l=m+1;
        }
        if(m*m<x)
            return m;
        else
            return m-1;
    }
};
