/*
 * @lc app=leetcode.cn id=1652 lang=cpp
 *
 * [1652] 拆炸弹
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        if (k != 0)
        {
            int p = 0;
            int n = code.size();
            vector<int> st(code.size(), 0);
            for (int i = 0; i < n; i++)
            {
                for (int j = 1; j <= abs(k); j++)
                {
                    st[i] += code[((i +n+ (k / abs(k)) * j)) % (n)];
                }
            }
            for (int i = 0; i < n; i++)
            {
                code[i] = st[i];
            }
            return code;
        }
        else
        {
            return vector<int>(code.size(), 0);
        }
    }
};
// @lc code=end
int main(void)
{
    Solution s;
    vector<int>v = {2,4,9,3};
    s.decrypt(v,-2);
    return 0;
}