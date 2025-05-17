class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int mid;

        while(low <= high){

            mid = (high - low)/2 + low;

            if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid -1]){
                return mid;
            }
            else if(arr[mid] < arr[mid+1]){
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }

        return -1;
    }
};