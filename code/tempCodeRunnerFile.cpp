/*
 * @lc app=leetcode.cn id=3145 lang=cpp
 * @lcpr version=30204
 *
 * [3145] 大数组元素的乘积
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
    vector<long  long> popcount(long  long n)
    {
        vector<long  long> tmp;
        while (n)
        {
            tmp.push_back(log2(n&-n));
            n -= n & -n;
        }
        return tmp;
    }

    vector<long  long> findProductsOfElements(vector<vector<long long>> queries)
    {
        int a ;
        cin>>a;
        // vector<long  long> st[1 << 17];
        for (long  long i = a; i <= a+100; i++)
        {
            cout<<i<<"___\t"<<bitset<32>(i);
            for (long  long j : popcount(i))
            {
                cout << j << " ";
            }
            cout << endl;
        }
        
        return {};
        // auto get_single = [&](long  long n) ->long  long
        // {
        //     for
        // };
    }
};
signed main()
{
    Solution s;
    s.findProductsOfElements({});
    system("pause");
    return 0;
}
// @lc code=end

/*
// @lcpr case=start
// [[1,3,7]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,5,3],[7,7,4]]\n
// @lcpr case=end

 */
