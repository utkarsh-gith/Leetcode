// first sort the elements in order of their starting time
// then create an array suffix which stores the biggest value next to the i-th
// index event (should be non - overlapping)
// run a loop till end of the events matrix
// find the first non-overlapping event
// compare the sum of i-th value and first non-overlapping event value
// to maxSum
// compare 

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<int> maxSuffix(n, 0); 

        maxSuffix[n - 1] = events[n - 1][2]; 

        for (int i = n - 2; i >= 0; --i) {
            maxSuffix[i] = max(events[i][2], maxSuffix[i + 1]);
        }

        int maxSum = 0;

        for (int i = 0; i < n; ++i) {
            
            int low = i + 1, high = n - 1, idx = -1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (events[mid][0] > events[i][1]) {
                    idx = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

           
            if (idx != -1) {
                maxSum = max(maxSum, events[i][2] + maxSuffix[idx]);
            }
            
            maxSum = max(maxSum, events[i][2]);
        }

        return maxSum;
    
    }
};