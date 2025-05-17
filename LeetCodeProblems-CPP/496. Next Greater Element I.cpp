// using map

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums2.size();
        map<int,int> find;

        find[nums2[n - 1]] = -1;
        for(int i = n - 2;i >= 0; i--){
            
            int j = i + 1;
            while(j < n  && nums2[j] < nums2[i]){
                j++;
            }
            if(j == n){
                find[nums2[i]] = -1;
            }else{
                find[nums2[i]] = nums2[j];
            }
        }

        n = nums1.size();
        vector<int> greater(n);

        for(int i = 0;i < n;i++){
            greater[i] = find[nums1[i]];
        }

        return greater;
        
    }
};