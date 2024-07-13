/*
 * @lc app=leetcode.cn id=502 lang=cpp
 *
 * [502] IPO
 */

// @lc code=start
#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &pro, vector<int> &cap)
    {
        // for (int i = 0; i < pro.size(); i++)
        // {
        //     arr.push_back({pro[i], cap[i]});
        // }
        // sort(arr.begin(), arr.end(), [](const pii &a, const pii &b)
        //      { return a.first < b.first; });
        vector<int> index(pro.size());
        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(),[&](const int &a,const int &b)
        {
            return cap[a]<cap[b];
        });
        priority_queue<int> aux;
        int ans = 0;
        int i = 0;

        while (k--)
        {
            for (; cap[index[i]] <= w; i++)
            {
                aux.push(pro[index[i]]);
            }
            if (!aux.empty())
            {
                w += aux.top();
                aux.pop();
            }
        }
        return w;
    }
};
// @lc code=end
