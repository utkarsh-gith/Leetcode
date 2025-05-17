class Solution {
public:
    int reverse(int x) {
    int s=0;
    while(x!=0)
    {
        if((s<-((pow(2,31)/10)))||(s>(((pow(2,31)-1)/10))))
            return 0;
        s=s*10+(x%10);
        x=x/10;
    }
    return s;
    }
};
