/*
 * @lc app=leetcode.cn id=LCR 085 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 085] 括号生成
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
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<string> re;
    void dfs(int lr, int ll, string ans)
    {
        if (ll == 0 && lr == 0)
        {
            re.push_back(ans);
        }
        else if (lr < ll||lr<0||ll<0)
        {
            return;
        }
        else
        {
            dfs(lr - 1, ll, ans + ")");
            dfs(lr, ll - 1, ans + "(");
            return;
        }
    }
    vector<string> generateParenthesis(int n)
    {
        dfs(n,n, string(""));
        return re;
    }
};
// @lc code=end

// int main(void)
// {
//     Solution s;
//     auto it = s.generateParenthesis(4);
//     for (auto &var : it)
//     {
//         cout << var << endl;
//     }
//     return 0;
// }

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
