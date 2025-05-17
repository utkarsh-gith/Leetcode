class Solution {
public:
    int histogram(vector<int> heights, int n){

        vector<int> left(n,0);
        vector<int> right(n,0);

        left[0] = -1;
        right[n - 1] = n;

        for(int i = 1;i < n; i++){

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
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> heights(m,0);
        int maxArea = 0;

        for(int i = 0;i < n; i++){
            for(int j = 0;j < m;j++){

                if(matrix[i][j] == '1'){
                    heights[j] += 1;
                }else{
                    heights[j] = 0;
                }
                
            }
            maxArea = max(maxArea,histogram(heights,m));
        }

        return maxArea;
        
    }
};

// OR

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

    int histogram(vector<int>& heights, int n) {
        
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> heights(m,0);
        int maxArea = 0;

        for(int i = 0;i < n; i++){
            for(int j = 0;j < m;j++){

                if(matrix[i][j] == '1'){
                    heights[j] += 1;
                }else{
                    heights[j] = 0;
                }
                
            }
            maxArea = max(maxArea,histogram(heights,m));
        }

        return maxArea;
        
    }
};