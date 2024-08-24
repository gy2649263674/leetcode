/*
 * @lc app=leetcode.cn id=2101 lang=cpp
 * @lcpr version=30204
 *
 * [2101] 引爆最多的炸弹
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
    int bom(vector<vector<int>> &arr, int root)
    {
        int cnt = 1;
        bool vis[101] = {false};
        vis[root] = 1;
        queue<int> aux;
        aux.push(root);
        while (aux.empty() == false)
        {
            int cur = aux.front();
            for (auto var : arr[cur])
            {
                if (vis[var] == false)
                {
                    aux.push(var);
                    vis[var] = 1;
                    ++cnt;
                }
            }
            aux.pop();
        }
        return cnt;
    }
    int maximumDetonation(vector<vector<int>> &bombs)
    {
        int n = bombs.size();
        vector<vector<int>> mp(n + 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j &&
                    (static_cast<long long>((bombs[i][0] - bombs[j][0])) * static_cast<long long>((bombs[i][0] - bombs[j][0])) + static_cast<long long>(bombs[i][1] - bombs[j][1]) * static_cast<long long>(bombs[i][1] - bombs[j][1])) <= static_cast<long long>(bombs[i][2]) * static_cast<long long>(bombs[i][2]))
                {
                    mp[i].push_back(j);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, bom(mp, i));
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[2,1,3],[6,1,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,5],[10,10,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[2,3,1],[3,4,2],[4,5,3],[5,6,4]]\n
// @lcpr case=end

 */
