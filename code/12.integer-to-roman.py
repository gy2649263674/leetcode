#
# @lc app=leetcode.cn id=12 lang=python3
# @lcpr version=30204
#
# [12] 整数转罗马数字
#
# https://leetcode.cn/problems/integer-to-roman/description/
#
# algorithms
# Medium (67.95%)
# Likes:    1341
# Dislikes: 0
# Total Accepted:    518.4K
# Total Submissions: 762.2K
# Testcase Example:  '3749'
#
# 七个不同的符号代表罗马数字，其值如下：
# 
# 
# 
# 
# 符号
# 值
# 
# 
# 
# 
# I
# 1
# 
# 
# V
# 5
# 
# 
# X
# 10
# 
# 
# L
# 50
# 
# 
# C
# 100
# 
# 
# D
# 500
# 
# 
# M
# 1000
# 
# 
# 
# 
# 罗马数字是通过添加从最高到最低的小数位值的转换而形成的。将小数位值转换为罗马数字有以下规则：
# 
# 
# 如果该值不是以 4 或 9 开头，请选择可以从输入中减去的最大值的符号，将该符号附加到结果，减去其值，然后将其余部分转换为罗马数字。
# 如果该值以 4 或 9 开头，使用 减法形式，表示从以下符号中减去一个符号，例如 4 是 5 (V) 减 1 (I): IV ，9 是 10 (X) 减
# 1 (I)：IX。仅使用以下减法形式：4 (IV)，9 (IX)，40 (XL)，90 (XC)，400 (CD) 和 900 (CM)。
# 只有 10 的次方（I, X, C, M）最多可以连续附加 3 次以代表 10 的倍数。你不能多次附加 5 (V)，50 (L) 或 500
# (D)。如果需要将符号附加4次，请使用 减法形式。
# 
# 
# 给定一个整数，将其转换为罗马数字。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：num = 3749
# 
# 输出： "MMMDCCXLIX"
# 
# 解释：
# 
# 3000 = MMM 由于 1000 (M) + 1000 (M) + 1000 (M)
# ⁠700 = DCC 由于 500 (D) + 100 (C) + 100 (C)
# ⁠ 40 = XL 由于 50 (L) 减 10 (X)
# ⁠  9 = IX 由于 10 (X) 减 1 (I)
# 注意：49 不是 50 (L) 减 1 (I) 因为转换是基于小数位
# 
# 
# 
# 示例 2：
# 
# 
# 输入：num = 58
# 
# 输出："LVIII"
# 
# 解释：
# 
# 50 = L
# ⁠8 = VIII
# 
# 
# 
# 示例 3：
# 
# 
# 输入：num = 1994
# 
# 输出："MCMXCIV"
# 
# 解释：
# 
# 1000 = M
# ⁠900 = CM
# ⁠ 90 = XC
# ⁠  4 = IV
# 
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= num <= 3999
# 
# 
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
st = [(1000,'M'),
            (900,'CM'),
            (500,'D'),
            (400,'CD'),
            (100,'C'),
            (90,'XC'),
            (50,'L',),
            (40,'XL'),
            (10,'X'),
            (9,'IX'),
            (5,'V'),
            (4,'IV'),
            (1,'I'),
            (0,''),
]
class Solution:
    def intToRoman(self, num: int) -> str:
        ans:str = ''
        for k,v in st:
            while num >= k and num>0:
                num -= k
                ans+=v
        return ans
        s= str(num)
        if len(s) == 4:
            return st[1000]*(int(s[0])-0)+self.intToRoman(num-num//1000*1000)
        elif len(s) == 3:
            if int(s[0]) == 4:
                return st[400]+self.intToRoman(num-400)
            elif int(s[0]) == 9:
                return st[900]+self.intToRoman(num-900)
            elif int(s[0])>= 5:
                return st[500]+(int(s[0])-5)*st[100]+self.intToRoman(num-num//100*100)
            elif int(s[0]) < 4:
                return st[100]*(int(s[0])-0)+self.intToRoman(num-num//100*100)
        elif len(s) == 2:
            if int(s[0]) == 4:
                return st[40]+self.intToRoman(num-40)
            elif int(s[0]) == 9:
                return st[90]+self.intToRoman(num-90)
            elif int(s[0])>= 5:
                return st[50]+(int(s[0])-5)*st[10]+self.intToRoman(num-num//10*10)
            elif int(s[0]) < 4:
                return st[10]*(int(s[0])-0)+self.intToRoman(num-num//10*10)
        elif len(s) == 1:
            if int(s[0]) == 4:
                return st[4]
            elif int(s[0]) == 9:
                return st[9]
            elif int(s[0])>= 5:
                return st[5]+(int(s[0])-5)*st[1]
            elif int(s[0]) < 4:
                return st[1]*(int(s[0])-0)
# @lc code=end
if __name__ == "__main__":
    # num = int(input())
    solution = Solution()
    num = 3749
    res = solution.intToRoman(num)
    print(res)


#
# @lcpr case=start
# 3749\n
# @lcpr case=end

# @lcpr case=start
# 58\n
# @lcpr case=end

# @lcpr case=start
# 1994\n
# @lcpr case=end

#

