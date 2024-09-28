/*
* @lc app=leetcode.cn id=2286 lang=cpp
* @lcpr version=30204
*
* [2286] 以组为单位订音乐会的门票
*
* https://leetcode.cn/problems/booking-concert-tickets-in-groups/description/
*
* algorithms
* Hard (25.39%)
* Likes:    53
* Dislikes: 0
* Total Accepted:    7K
* Total Submissions: 21.7K
* Testcase Example:  '["BookMyShow","gather","gather","scatter","scatter"]\n' +
'[[2,5],[4,0],[2,0],[5,1],[5,1]]'
*
* 一个音乐会总共有 n 排座位，编号从 0 到 n - 1 ，每一排有 m 个座椅，编号为 0 到 m - 1
* 。你需要设计一个买票系统，针对以下情况进行座位安排：
*
*
* 同一组的 k 位观众坐在 同一排座位，且座位连续 。
* k 位观众中 每一位 都有座位坐，但他们 不一定 坐在一起。
*
*
* 由于观众非常挑剔，所以：
*
*
* 只有当一个组里所有成员座位的排数都 小于等于 maxRow ，这个组才能订座位。每一组的 maxRow 可能 不同 。
* 如果有多排座位可以选择，优先选择 最小 的排数。如果同一排中有多个座位可以坐，优先选择号码 最小 的。
*
*
* 请你实现 BookMyShow 类：
*
*
* BookMyShow(int n, int m) ，初始化对象，n 是排数，m 是每一排的座位数。
* int[] gather(int k, int maxRow) 返回长度为 2 的数组，表示 k 个成员中 第一个座位 的排数和座位编号，这 k
* 位成员必须坐在 同一排座位，且座位连续 。换言之，返回最小可能的 r 和 c 满足第 r 排中 [c, c + k - 1] 的座位都是空的，且 r
* <= maxRow 。如果 无法 安排座位，返回 [] 。
* boolean scatter(int k, int maxRow) 如果组里所有 k 个成员 不一定 要坐在一起的前提下，都能在第 0 排到第
* maxRow 排之间找到座位，那么请返回 true 。这种情况下，每个成员都优先找排数 最小 ，然后是座位编号最小的座位。如果不能安排所有 k
* 个成员的座位，请返回 false 。
*
*
*
*
* 示例 1：
*
* 输入：
* ["BookMyShow", "gather", "gather", "scatter", "scatter"]
* [[2, 5], [4, 0], [2, 0], [5, 1], [5, 1]]
* 输出：
* [null, [0, 0], [], true, false]
*
* 解释：
* BookMyShow bms = new BookMyShow(2, 5); // 总共有 2 排，每排 5 个座位。
* bms.gather(4, 0); // 返回 [0, 0]
* ⁠                 // 这一组安排第 0 排 [0, 3] 的座位。
* bms.gather(2, 0); // 返回 []
* ⁠                 // 第 0 排只剩下 1 个座位。
* ⁠                 // 所以无法安排 2 个连续座位。
* bms.scatter(5, 1); // 返回 True
* ⁠                  // 这一组安排第 0 排第 4 个座位和第 1 排 [0, 3] 的座位。
* bms.scatter(5, 1); // 返回 False
* ⁠                  // 总共只剩下 1 个座位。
*
*
*
*
* 提示：
*
*
* 1 <= n <= 5 * 10^4
* 1 <= m, k <= 10^9
* 0 <= maxRow <= n - 1
* gather 和 scatter 总 调用次数不超过 5 * 10^4 次。
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
#include <numeric>
// @lcpr-template-end
// @lc code=start
#define pii pair<int, int>
#include <set>
class BookMyShow
{
    vector<int> used;
    vector<int> sum;

public:
    // int build(int cur,int l,int r)
    // {
    //     if(l == r)
    //     {
    //         return used[l] ==
    //     }
    //     int m = (l+r)>>1;
    //     // used[cur] = min()
    // }
    // all is 0 at start
    // used i is  the cseats used at the row
    int getmin(int cur, int l, int r, int tl, int tr)
    {
        if (tl >= l && tr <= r)
        {
            return used[cur];
        }
        else
        {
            int mid = (l + r) >> 1;
            int sl = cur << 1, sr = cur * 2 + 1;
            if(tl<)
            return min(getmin(sl, l, mid, tl, mid),

                       getmin(sr, mid + 1, r, mid + 1, tr));
        }
    }
    int searchmin()
    {
    }
    void getsum(int l, int r)
    {
    }
    void modifysum(int l, int r)
    {
    }
    void modifymin(int l, int r, int ind)
    {
        if (l == r)
        {
        }
    }
    int getindex()
    {
    }
    BookMyShow(int n, int m)
    {
    }

    vector<int> gather(int k, int maxRow)
    {
        if (k == 0)
        {
            return {};
        }
    }
    bool scatter(int k, int maxRow)
    {
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */
// @lc code=end
// ["BookMyShow","scatter","gather","gather","gather"]
// ' +
//   '[[3,999999999],[1000000000,2],[999999999,2],[999999999,2],[999999999,2]]
int main(void)
{
    BookMyShow bms(3, 999999999);
    bms.scatter(1000000000, 2);
    bms.gather(999999999, 2);
    bms.gather(999999999, 2);
    bms.gather(999999999, 2);
    return 0;
}

/*
// @lcpr case=start
// ["BookMyShow", "gather", "gather", "scatter", "scatter"][[2, 5], [4, 0], [2, 0], [5, 1], [5, 1]]\n
// @lcpr case=end

*/
// public:
//     /*
//     // @lcpr case=start
//     // ["BookMyShow", "gather", "gather", "scatter", "scatter"][[2, 5], [4, 0], [2, 0], [5, 1], [5, 1]]\n
//     // @lcpr case=end

//     */
//     deque<set<pii>> mp;
//     vector<multiset<int>> mx;
//     BookMyShow(int n, int m)
//     {
//         // mp = vector<pii>(n,{0,m});
//         mp = deque<set<pii>>(n, set<pii>());
//         mx = vector<multiset<int>>(n, multiset<int>());
//         for (int i = 0; i < n; i++)
//         {
//             mx[i].insert({m});
//             mp[i].insert({0, m - 1});
//         }
//         // record the
//         //  record the able of start and end
//         // [0,m]
//         // -1, m+1;
//     }
//     // just simulate is enough
//     vector<int> gather(int k, int maxRow)
//     {
//         int cur = mp.size();
//         for (int i = 0; i <= maxRow; i++)
//         {
//             if (!mx[i].empty() && *mx[i].rbegin() >= k)
//             {
//                 for (auto interval : mp[i])
//                 {
//                     if (interval.second - interval.first + 1 >= k)
//                     {
//                         int l = interval.first;
//                         int r = interval.second;

//                         if (interval.second - interval.first + 1 != k)
//                         {
//                             mp[i].insert({interval.first + k, interval.second});
//                             mx[i].insert(-interval.first - k + interval.second + 1);
//                         }
//                         mx[i].erase(mx[i].find(interval.second - interval.first + 1));
//                         mp[i].erase(interval);
//                         return {i, l};
//                     }
//                 }
//             }
//             // for()
//         }
//         return {};
//     }

//     bool scatter(int k, int maxRow)
//     {
//         long long sum = 0;
//         for (int i = 0; i <= maxRow; i++)
//         {
//             sum+=accumulate(mx[i].begin(), mx[i].end(), 0ll);
//         }
//         if (k > sum)
//         {
//             return false;
//         }
//         int n = mp.size();
//         for (int i = 0; i <= maxRow && k > 0; i++)
//         {
//             //[null, [], true, [], [], [0, 3]] [null, [], true, [1, 0], [], [0, 3]]
//             while (k > 0 && !mx[i].empty())
//             {
//                 auto v = *(mp[i].begin());
//                 int dis = v.second - v.first + 1;
//                 if (k >= v.second - v.first + 1)
//                 {
//                     mp[i].erase(v);
//                     mx[i].erase(mx[i].find(dis));
//                 }
//                 else
//                 {
//                     mp[i].erase(v);
//                     mx[i].erase(mx[i].find(v.second - v.first + 1));
//                     mp[i].insert({v.first + k, v.second});
//                     mx[i].insert(v.second - v.first - k + 1);
//                 }
//                 k -= dis;
//             }
//         }
//         return k <= 0;
//     }