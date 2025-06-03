//Idea - traverse one list and set map value to true, the check if map value true and other one false the push_back

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> inter;
        map<int,bool> v1,v2;
        for(int i=0;i<nums1.size();i++){
            v1[nums1[i]] = true;
        }
        for(int i=0;i<nums2.size();i++){
            if(v1[nums2[i]] == true && v2[nums2[i]] == false){
                inter.push_back(nums2[i]);
                v2[nums2[i]] = true;
            }
        }
        return inter;
    }
};

// OR
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> res;
        int i = 0, j = 0;
        int n1 = nums1.size(), n2 = nums2.size();

       while(i < n1 && j < n2){
            if(nums1[i] == nums2[j]){
                if(res.empty() || res.back() != nums1[i]) {
                    res.push_back(nums1[i]);
                }
                i++;
                j++;
            } else if(nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }

        return res;
    }
};

// OR

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> res;
        int k1 = 0, k2 = 0;
        int n1 = nums1.size(), n2 = nums2.size();

        while(k1 < n1 && k2 < n2){
            if(nums1[k1] == nums2[k2]){
                int k = nums1[k1];
                res.push_back(k);
                while(k1 < n1 && nums1[k1] == k){
                    k1++;
                }
                while(k2 < n2 && nums2[k2] == k){
                    k2++;
                }
            }else{
                if(nums1[k1] < nums2[k2]){
                    k1++;
                }else{
                    k2++;
                }
            }
        }

        return res;
    }
};

// Time Complexity:
// 	•	Sorting nums1: O(n log n)
// 	•	Sorting nums2: O(m log m)
// 	•	Two-pointer traversal: O(n + m)

// ➡️ Total Time:
// O(n log n + m log m)
// (where n = nums1.size() and m = nums2.size())

// Space Complexity:
// 	•	Output vector: O(k) (for intersection)
// 	•	Otherwise, O(1) extra space
