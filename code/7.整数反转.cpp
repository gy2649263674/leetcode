/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
using namespace std;
class Solution
{
public:
    int reverse(int x)
    {
        if (x == 0)
        {
            return 0;
        }
        string temp(to_string(abs(x)));
        std::reverse(temp.begin(), temp.end());
        int re = atoi(&temp[0]);
        if (re < 0)
        {
            return 0;
        }
        else
        {
            if(temp.length()>=10&&temp[0]>= '3')
            {
                return 0;
            }
            return x / abs(x) * re;
        }
    }
};
// @lc code=end
