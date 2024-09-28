# import *
class Solution:
    def differenceOfSum(self, nums: list[int]) -> int:
        # newlist = [List(str(i)) for i in nums ]
        newlist = []
        for ss in nums:
            # sub = List(str(i))
            newlist.append([int(i) for i in str(ss)])
            
        return  abs(sum(newlist)-sum[List])
