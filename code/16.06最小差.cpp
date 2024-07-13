#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int smallestDifference(vector<int> &a, vector<int> &b)
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int ap = 0, bp = 0;
        long long ans = 8e9;
        while (ap < a.size())
        {
            ans = min(static_cast<long long>(labs(static_cast<long long>(a[ap] - b[bp]))), ans);
            if (a[ap] - b[bp] < 0)
            {
                ++ap;
            }
            else if (a[ap] - b[bp] > 0)
            {
                ++bp;
            }
            else{
                return 0;
            }
        }
    }
        return ans;
};
