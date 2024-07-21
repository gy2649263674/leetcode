/*
 * @lc app=leetcode.cn id=2956 lang=cpp
 * @lcpr version=30204
 *
 * [2956] 找到两个数组中的公共元素
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
#include <bits/stdc++.h>
class Solution
{
public:
    vector<int> findIntersectionValues(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> st(nums1.begin(), nums1.end());
        int ans2 = 0;
        for (int i = 0; i < nums2.size(); i++)
        {
            if (st.count(nums2[i]))
            {
                ++ans2;
            }
        }
        st.clear();
        st.insert(nums2.begin(), nums2.end());
        int ans1 = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            if (st.count(nums1[i]))
            {
                ++ans1;
            }
        }
        return {ans1, ans2};
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,2]\n[1,2]\n
// @lcpr case=end

// @lcpr case=start
// [4,3,2,3,1]\n[2,2,5,2,3,6]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,2,3]\n[1,5]\n
// @lcpr case=end

 */
