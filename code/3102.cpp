/*
 * @lc app=leetcode.cn id=3102 lang=cpp
 * @lcpr version=30204
 *
 * [3102] 最小化曼哈顿距离
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
#include <bits/stdc++.h> // @lcpr-template-end
//@lc code=start

// deque<int> sub;
//         deque<int> add;
//         for (auto &it : arr)
//         {
//             sub.push_back(it[0] - it[1]);
//             add.push_back(it[0] + it[1]);
//         }
//         sort(sub.begin(), sub.end());
//         sort(add.begin(), add.end());
//         int ans = max(abs((sub.front() - *(sub.rbegin() + 1))),
//                       abs((add.front() - *(add.rbegin() + 1))));
//         ans = min(ans, max(abs(*(sub.begin() + 1) - sub.back()),
//                            abs(*(add.begin() + 1) - add.back())));
//         return ans;

class Solution
{
public:
    int minimumDistance(vector<vector<int>>& points)
    {
        multiset<int> sub;
        multiset<int> add;
        int n = points.size();
        for (auto &it : points)
        {
            sub.insert(it[0] - it[1]);
            add.insert(it[0] + it[1]);
        }
        int ans = 1e9;
        for (int j = 0; j < n; j++)
        {
            sub.erase(sub.find(points[j][0] - points[j][1]));
            add.erase(add.find(points[j][0]+ points[j][1]));
            ans = min(max((*sub.rbegin()-*sub.begin()),(*add.rbegin()-*add.begin())),ans);
            sub.insert(points[j][0] - points[j][1]);
            add.insert(points[j][0] + points[j][1]);
            
        }
        return ans;
    }
};

// @lc code=end

/*
// @lcpr case=start
// [[3,10],[5,15],[10,2],[4,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[1,1],[1,1]]\n
// @lcpr case=end

 */
// int main(void)
// {
//     Solution ss;
//     ss.minimumDistance({{3, 10}, {5, 15}, {10, 2}, {4, 4}});
//     return 0;
// }