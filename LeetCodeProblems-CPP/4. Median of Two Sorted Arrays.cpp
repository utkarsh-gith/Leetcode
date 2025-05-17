// Optimal

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        int k = (n + m - 1)/2;
        int flag = ((n + m) % 2 == 0) ? 1 : 0;
        double temp;
        int i = 0, j = 0;

        while(i < n && j < m && i + j <= k){
            if(nums1[i] <= nums2[j]){
                temp = nums1[i++];
            }else{
                temp = nums2[j++];
            }
        }

        if(i + j <= k){
            while(i + j <= k){
                if(i < n){
                    while(i + j <= k){
                        temp = nums1[i++];
                    }
                }else{
                    while(i + j <= k){
                        temp = nums2[j++];
                    }
                }
            }
        }

        if(flag){
            if(i < n && j < m){
                if(nums1[i] <= nums2[j]){
                    temp += nums1[i++];
                }else{
                    temp += nums2[j++];
                }
            }else if(i < n){
                temp += nums1[i++];
            }else{
                temp += nums2[j++];
            }
            temp /= 2;
        }

        return temp;
    }
};

// OR

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0,k,m=nums1.size(),n=nums2.size();
        vector<int> nums;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                nums.push_back(nums1[i]);
                i++;
            }
            else{
                nums.push_back(nums2[j]);
                j++;
            }
        }
        if(i<m){
            while(i<m){
                nums.push_back(nums1[i]);
                i++;
            }
        }
        else{
            while(j<n){
                nums.push_back(nums2[j]);
                j++;
            }
        }
        k=nums.size();
        if(k%2==0){
            double l = double(nums[(k-1)/2]+nums[(k-1)/2 + 1])/2;
            return l;
        }
        return nums[(k-1)/2];
    }
};