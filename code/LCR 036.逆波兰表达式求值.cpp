/*
 * @lc app=leetcode.cn id=LCR 036 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 036] 逆波兰表达式求值
 *
 * https://leetcode.cn/problems/8Zf90G/description/
 *
 * algorithms
 * Medium (54.42%)
 * Likes:    61
 * Dislikes: 0
 * Total Accepted:    37K
 * Total Submissions: 68K
 * Testcase Example:  '["2","1","+","3","*"]'
 *
 * 根据 逆波兰表示法，求该后缀表达式的计算结果。
 *
 * 有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
 *
 *
 *
 * 说明：
 *
 *
 * 整数除法只保留整数部分。
 * 给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：tokens = ["2","1","+","3","*"]
 * 输出：9
 * 解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
 *
 *
 * 示例 2：
 *
 * 输入：tokens = ["4","13","5","/","+"]
 * 输出：6
 * 解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
 *
 *
 * 示例 3：
 *
 * 输入：tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
 * 输出：22
 * 解释：
 * 该算式转化为常见的中缀算术表达式为：
 * ⁠ ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= tokens.length <= 10^4
 * tokens[i] 要么是一个算符（"+"、"-"、"*" 或 "/"），要么是一个在范围 [-200, 200] 内的整数
 *
 *
 *
 *
 * 逆波兰表达式：
 *
 * 逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。
 *
 *
 * 平常使用的算式则是一种中缀表达式，如 ( 1 + 2 ) * ( 3 + 4 ) 。
 * 该算式的逆波兰表达式写法为 ( ( 1 2 + ) ( 3 4 + ) * ) 。
 *
 *
 * 逆波兰表达式主要有以下两个优点：
 *
 *
 * 去掉括号后表达式无歧义，上式即便写成 1 2 + 3 4 + * 也可以依据次序计算出正确结果。
 * 适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中。
 *
 *
 *
 *
 * 注意：本题与主站 150 题相同：
 * https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
 *
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <bits/stdc++.h>
#define LOCAL
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int getRes(int a, int b, char op)
    {
        if (op == '+')
            return a + b;
        if (op == '-')
            return a - b;
        if (op == '*')
            return a * b;
        if (op == '/' && b != 0)
            return a / b;
        return 0;
    }
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stk;
        for (auto c : tokens)
        {
            if (c.length() > 1 || isdigit(c[0]))
            {
                stk.push(stoi(c));
            }
            else
            {
                int op1 = stk.top();
                stk.pop();
                int op2 = stk.top();
                stk.pop();
                stk.push(getRes(op2, op1, c[0]));
            }
        }
        return stk.top();
    }
};
// @lc code=end
int main(int argc, const char **argv)
{
    Solution s;
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << s.evalRPN(tokens) << endl;
    return 0;
}
/*
// @lcpr case=start
// ["2","1","+","3","*"]\n
// @lcpr case=end

// @lcpr case=start
// ["4","13","5","/","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]\n
// @lcpr case=end

 */
