#
# @lc app=leetcode.cn id=2844 lang=python3
# @lcpr version=30204
#
# [2844] 生成特殊数字的最少操作
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def minimumOperations(self, num: str) -> int:
        if len(num) == 1 :
            return 0 if num == '0' else 1
        h5 = -1
        h0 = -1
        n = len(num)
        for i in range(len(num)-1,0):
            if num[i] == '5':
                h5 = i
                if h0 != -1:
                    return n-i-2
            if num[i] == '0':
                h0 = i
                if h0!= -1:
                    return n-i-2
            if (num[i] == '2' or num[i] == '7')and h5 != -1:
                return n-i-2
# @lc code=end
print(Solution ().minimumOperations("2245047"))





#
# @lcpr case=start
# "2245047"\n
# @lcpr case=end

# @lcpr case=start
# "2908305"\n
# @lcpr case=end

# @lcpr case=start
# "10"\n
# @lcpr case=end

#

