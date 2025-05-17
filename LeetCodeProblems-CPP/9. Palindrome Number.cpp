class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return 0;
        long int y=0,z=x;
        while(z!=0)
        {
            y=y*10+z%10;
            z /= 10;
        }
        if(x==y)
            return 1;  
        else
            return 0;
    }
};
