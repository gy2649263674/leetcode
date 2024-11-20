/*
 * @lc app=leetcode.cn id=633 lang=cpp
 * @lcpr version=30204
 *
 * [633] 平方数之和
 *
 * https://leetcode.cn/problems/sum-of-square-numbers/description/
 *
 * algorithms
 * Medium (37.95%)
 * Likes:    482
 * Dislikes: 0
 * Total Accepted:    152.6K
 * Total Submissions: 398.3K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a^2 + b^2 = c 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：c = 5
 * 输出：true
 * 解释：1 * 1 + 2 * 2 = 5
 * 
 * 
 * 示例 2：
 * 
 * 输入：c = 3
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= c <= 2^31 - 1
 * 
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
// @lcpr-template-end
// @lc code=start
#include<bits/stdc++.h>
class Solution {
public:
    bool judgeSquareSum(int c) {
        // vector<bool>issq(int(1e5));
        map<long long,bool>issq;
        for(long long i = 0;i*i<=INT_MAX&&i*i>=0;i++)
        {
            issq[i*i] = true;
        }
        // for(int i = 0;)
        for(auto [val,_]:issq)
        {
            if(issq.count(c-val))
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */

