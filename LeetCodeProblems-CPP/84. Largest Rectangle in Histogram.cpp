// Brute-Force (Time Limit Exceeds)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        int maxArea = 0;

        for(int i = 0;i < n;i++){
            
            int j = i, k = i;
            while(j > 0 && heights[j-1] >= heights[i]){
                j--;
            }
            while(k < n - 1 && heights[k + 1] >= heights[i]){
                k++;
            }
            int area = (k - j + 1) * heights[i];
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

// Using stack

class Solution {
public:
    void nextSmaller(vector<int>& next, vector<int> heights, int n){

        stack<int> s;
        s.push(-1);
        
        for(int i = n - 1;i >= 0;i--){
            int curr = heights[i];
            while(s.top() != -1 && heights[s.top()] >= curr){
                s.pop();
            }
            next[i] = s.top();
            s.push(i);
        }

    }

    void prevSmaller(vector<int>& prev, vector<int> heights, int n){

        stack<int> s;
        s.push(-1);
        
        for(int i = 0;i < n;i++){
            int curr = heights[i];
            while(s.top() != -1 && heights[s.top()] >= curr){
                s.pop();
            }
            prev[i] = s.top();
            s.push(i);
        }

    }

    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        
        vector<int> next(n);
        nextSmaller(next,heights,n);

        vector<int> prev(n);
        prevSmaller(prev,heights,n);

        int maxArea = INT_MIN;

        for(int i = 0;i < n;i++){

            if(next[i] == -1){
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;

            int area = heights[i] * b;
            maxArea = max(maxArea,area);
            
        }

        return maxArea;
    }
};

// same logic without stack

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return heights[0];
        }

        vector<int> left(n);
        vector<int> right(n);
        
        left[0] = -1;
        right[n - 1] = n;
        
        for(int i = 1; i < n; i++){

            int prev = i - 1;
            while(prev >= 0 && heights[prev] >= heights[i]){
                prev = left[prev];
            }
            left[i] = prev;

        }

        for(int i = n - 2; i >= 0; i--){

            int prev = i + 1; 
            while(prev < n && heights[prev] >= heights[i]){
                prev = right[prev]; 
            }
            right[i] = prev;

        }

        int maxArea = 0;
        for(int i = 0; i < n; i++){
            int width = right[i] - left[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }

        return maxArea;
        
    }
};