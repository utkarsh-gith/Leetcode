// Idea: run a while loop until count is equal to c and i is less than equal to k
//       if c!=k, the there are less factors than k, return -1

class Solution {
public:
    int kthFactor(int n, int k) {
        int i=2,c=1;
        while(c<k && i<=n)
        {
            if(n%i==0)
                c++;
            i++;
        }
        if(c!=k)
            return -1;
        return i-1;
    }
};
