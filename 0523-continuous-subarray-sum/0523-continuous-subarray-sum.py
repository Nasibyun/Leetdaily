class Solution:
    def checkSubarraySum(self, nums: list[int], k: int) -> bool:
        ans = set()
        sum=0
        for i in range(len(nums)):
            tsum = (sum+nums[i])%k 
            if tsum in ans:
                return True
            ans.add(sum)
            sum = tsum
        return False