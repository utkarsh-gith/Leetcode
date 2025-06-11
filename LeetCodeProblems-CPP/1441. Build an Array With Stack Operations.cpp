// Question Link - https://leetcode.com/problems/build-an-array-with-stack-operations/

/*
Approach 1: Simulate Stack Building from Stream [1...n]

- Iterate through numbers from 1 to n (the stream).
- For each number:
    - Always "Push" it onto the simulated stack.
    - If the number matches the current element in `target`, move to the next target index.
    - If it doesn't match, immediately "Pop" it (since it's not needed in the final stack).
- Stop the process once all elements in `target` are matched.

Time Complexity: O(n), Space Complexity: O(m)
- where n is the given upper limit and m = target.size()
*/

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int k = 0;

        for(int i = 1;i <= n; i++){
            res.push_back("Push");

            if(target[k] != i){
                res.push_back("Pop");
            }else{
                k++;
            }

            if(k == target.size()){
                break;
            }
        }

        return res;
    }
};


/*
Optimized Approach 2: Skip Unwanted Numbers Efficiently

- Initialize curr = 1 to track the stream.
- For each number x in target:
    - While curr < x:
        - Push and immediately Pop (skip unwanted numbers).
        - Increment curr.
    - Push x (which matches the target).
    - Increment curr.
- This avoids looping all the way to n.

Time Complexity: O(m + skipped), Space Complexity: O(m)
- where m = target.size(), skipped = number of elements not in target before each x
*/

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int curr = 1;

        for (int x : target) {
            while (curr < x) {
                res.push_back("Push");
                res.push_back("Pop");
                curr++;
            }
            res.push_back("Push");
            curr++;
        }

        return res;
    }
};