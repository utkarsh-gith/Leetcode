/*
Approach: 
We are given two sorted arrays, and our task is to merge them such that the result is stored in the first array, 
which has enough space to hold all elements.

This is a classic two-pointer problem:
	1.	Use one pointer to track the last non-zero element in the first array.
	2.	Use a second pointer for the last element in the second array.
	3.	Use a third pointer to track the last index of the first array (i.e., where the merged elements go).

Now, compare the elements pointed to by the first two pointers. Place the larger element at the index pointed 
to by the third pointer, and move the pointers backward accordingly.

Continue this process until one of the first two pointers goes out of bounds.

Finally, if there are any remaining elements in the second array, copy them into the first array.

Time Complexity: O(m + n), where m and n are number of elements in  nums1 and nums2
Space Complexity: O(1), constant extra space is used because the merge is done in-place in nums1.
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1;
        m--;
        n--;

        while(m >= 0 && n >= 0){
            if(nums1[m] > nums2[n]){
                nums1[k--] = nums1[m--];
            }else{
                nums1[k--] = nums2[n--];
            }
        }

        while(n >= 0){
            nums1[k--] = nums2[n--];
        }
    }
};