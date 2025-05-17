class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        j = 1
        for i in range(len(nums) - 1):
            if nums[i] != nums[i + 1]:
                nums[j] = nums[i + 1]
                j += 1
        return j
        

// OR (Using Sets)

class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        k = len(nums)
        ans = list(set(nums))
        ans.sort()
        for i in range(len(ans)):
            nums[i] = ans[i]
        return len(ans)
