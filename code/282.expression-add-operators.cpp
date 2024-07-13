/*
 * @lc app=leetcode.cn id=282 lang=cpp
 * @lcpr version=30204
 *
 * [282] 给表达式添加运算符
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
    string s;
    int tar;
    vector<string>ans;
    void dfs(int n, int pre, int sum, string ex)
    {
        if (n ==s.length() -1 )
        {
            if(sum+ s[n] == tar)
            {   
                ans.push_back(ex+"+"+to_string(s[n]));
            }
            if(sum- s[n] == tar)
            {   
                ans.push_back(ex+"-"+to_string(s[n]));
            }
            if(sum-pre+pre*s[n] == tar)
            {
                ans.push_back(ex+"*"+to_string(s[n]));
            }
        }
        else
        {
            dfs(n+1,(s[n]-'0')*pre,sum-pre+pre*(s[n]-'0'),ex+"*"+to_string(s[n]));//*
            dfs(n+1,(s[n]-'0')+pre,sum-(s[n]-'0'),ex+"-"+to_string(s[n]));//-
            dfs(n+1,-(s[n]-'0')+pre,sum+pre*(s[n]-'0'),ex+"+"+to_string(s[n]));//+
        }
        return ;
    }
    vector<string> addOperators(string num, int target)
    {
        dfs(1,s[0]-'0',s[0]-'0',string()+s[0]);
        return  ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "123"\n6\n
// @lcpr case=end

// @lcpr case=start
// "232"\n8\n
// @lcpr case=end

// @lcpr case=start
// "3456237490"\n9191\n
// @lcpr case=end

 */
