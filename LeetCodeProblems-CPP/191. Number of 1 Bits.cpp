class Solution {
public:
    int hammingWeight(uint32_t n) {
        int s=0;
        while(n!=0)
        {
            if(n&1)
                s++;
            n=n>>1;
        }
        return s;
    }
};