/*
 * @lc app=leetcode.cn id=551 lang=cpp
 * @lcpr version=30204
 *
 * [551] 学生出勤记录 I
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
#include<bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    bool checkRecord(string&s)
    {
        int A = 0;
        int L = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'A')
            {
                ++A;
            }
            if (s[i] == 'L')
            {
                ++L;
            }
            else
            {
                L = 0;
            }
            if(L>=3||A == 2)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "PPALLP"\n
// @lcpr case=end

// @lcpr case=start
// "PPALLL"\n
// @lcpr case=end

 */
