#include<bitset>
using namespace std;
class Solution
{
public:
    int longestAwesome(string s)
    {
        int cur = 0;
        map<int, int> mp;
        int ans = 1;
        int val = 0;
        int(*ex)[10] = new int[s.length()+5][10]();
        //mp[0] = s[0] == '0'?0:0;
        mp[0] = 0;
        for (int i = 0; i < s.length(); i++)
        {
            val ^= 1 << (s[i] - '0');
            if (mp.count(val))
            {
                ans = max(ans, i + 1 - mp[val]);
            }
            else
            {
                mp[val] = i + 1;
            }
            for (int j = 0; j <= 9; j++)
            {
                ex[i+1][j] = ex[i][j] + (s[i]-'0' == j?1:0);
                int pos = val ^ (1 << j);
                if (mp.count(pos))
                {
                    ans = max(ans, i+1 - mp[pos]);
                    //区间自动收缩
                    
                    // if (ex[i+1][j] - ex[mp[pos]][j] > 0)
                    // //无需判断
                    // {
                    // }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
int main(void)
{
    GETS;
    Solution s;
    string st;
    while (cin >> st)
    {
        cout << s.longestAwesome(st) << endl;
    }
    return 0;
}