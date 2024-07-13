/*
 * @lc app=leetcode.cn id=301 lang=cpp
 * @lcpr version=30204
 *
 * [301] 删除无效的括号
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
    const int inf = 100;
    int mint = inf;
    bool legal(const string&a)
    {
        int l = 0,r = 0;
        for(int i = 0;i<a.length();i++)
        {
            if(a[i] == '(') 
            {
                ++l;
            }
            else if(a[i] == ')')
            {
                ++r;
            }
            if(l>r)
            {
                return false;
            }
        }
        return true;
    }
    void violent(string s, int ti)
    {
        if(ti>inf)
        {
            return ;
        }
        else
        {
            for(int i = 0;i<)
        }
    }
    vector<string> removeInvalidParentheses(string s)
    {
    }
};
// @lc code=end

/*
// @lcpr case=start
// "()())()"\n
// @lcpr case=end

// @lcpr case=start
// "(a)())()"\n
// @lcpr case=end

// @lcpr case=start
// ")("\n
// @lcpr case=end

 */
