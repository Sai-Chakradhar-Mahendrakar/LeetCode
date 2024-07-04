'''
    Using 1d array dp
    same as house robber 1 using as reference
    working on starting node and ending node
'''

class Solution:
    def rob(self, nums: List[int]) -> int:
        return max(nums[0],self.helper(nums[1:]),self.helper(nums[:-1]))

    def helper(self, nums):
        r1,r2 = 0,0

        for n in nums:
            te = max(r1+n, r2)
            r1 = r2
            r2 = te
        return r2