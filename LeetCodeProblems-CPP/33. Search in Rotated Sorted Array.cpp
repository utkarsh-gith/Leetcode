// Idea: Rotated Sorted Array, so binary search
//       First search the mid element if it matches with the target
//       Thrn if mid elemnt is less than last element, we know pivot element is in first half,
//       so check if the target lies in second half, if yes l=m+1 else h=m-1
//       else the pivot element will be in second half
//       check if target lies in first half, if yes h=m-1 else l=m+1

//Time Complexity: O(log(n)), because binary search


class Solution {
public:
    int search(vector<int>& a, int target) {
        int h = a.size()-1;
        int l=0,m;
        while(l<=h)
        {
            m=l+(h-l)/2;
            if(a[m] == target)
                return m;
            else if(a[m]<a[h])
            {
                if(target>a[m] && target<=a[h])
                    l=m+1;
                else
                    h=m-1;
            }
            else
            {
                if(target>=a[l] && target<a[m])
                    h=m-1;
                else
                    l=m+1;
            }
        }
        return -1;
    }
};
