class Solution:
    def checkSubarraySum(self, nums: list[int], k: int) -> bool:
        mp = {0:-1}
        flag = False
        sum=0
        for i in range(len(nums)):
            sum += nums[i]
            rem = sum%k
            if rem in mp:
                if i-mp[rem] >= 2:
                    flag = True
            else:
                mp[rem] = i

        return flag