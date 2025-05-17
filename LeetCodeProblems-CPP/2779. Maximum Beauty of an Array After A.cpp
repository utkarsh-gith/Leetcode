class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        
        int i = 0;
        int maxBeauty = 0;

        for (int j = 0; j < nums.size(); j++) {

            while (nums[j] - nums[i] > 2 * k) {
                i++;
            }

            maxBeauty = max(maxBeauty, j - i + 1);
        }

        return maxBeauty;
    }
};