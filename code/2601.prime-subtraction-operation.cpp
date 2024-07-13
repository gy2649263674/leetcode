/*
 * @lc app=leetcode.cn id=2601 lang=cpp
 * @lcpr version=30204
 *
 * [2601] 质数减法运算
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
    vector<int> prime;
    vector<bool> is;
    void sieve(int n)
    {
        is = vector<bool>(n+1,true);
        is[1] = false;
        is[2] = true;
        for (int i = 0; i < n; i++)
        {
            if(is[i])
            {
                prime.push_back(i);
            }
            for(int j = 0;i*j<= n&&j<prime.size();j++)
            {
                is[prime[j]*i] = false;
                if(i%prime[j] == 0)
                {
                    break;
                }
            }
        }
    }
    bool primeSubOperation(vector<int> &nums)
    {
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,9,6,10]\n
// @lcpr case=end

// @lcpr case=start
// [6,8,11,12]\n
// @lcpr case=end

// @lcpr case=start
// [5,8,3]\n
// @lcpr case=end

 */
