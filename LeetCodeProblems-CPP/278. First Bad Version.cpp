// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long int low = 1;
        long int high = n;

        while(low<=high){

            long int mid = (high - low)/2 + low;

            if(isBadVersion(mid) == 0){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
};