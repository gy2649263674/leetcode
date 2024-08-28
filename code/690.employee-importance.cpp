/*
 * @lc app=leetcode.cn id=690 lang=cpp
 * @lcpr version=30204
 *
 * [690] 员工的重要性
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
/*
// Definition for Employee.
*/
#if 0
class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
};
#endif
#include <map>
class Solution
{
public:
    int getImportance(vector<Employee *> employees, int id)
    {
        sort(employees.begin(), employees.end(), [](Employee *a, Employee *b)
             { return a->id < b->id; });
        map<int, Employee *> mp;
        for(auto &var:employees)
        {
            mp[var->id] = var;
        }
        int ans = 0;
        map<int,bool>vis;
        function<int(int)> f = [&](int i) -> int
        {
            if (vis.count(i))
            {
                return 0;
            }
            int tmp = 0;
            vis[i] = true;
            for (int iid : mp[i]->subordinates)
            {
                tmp += f(iid);
            }
            return tmp + mp[i]->importance;
        };
        return f(id);
    }
};
// @lc code=end
int main(void)
{
}
/*
// @lcpr case=start
// [[1,5,[2,3]],[2,3,[]],[3,3,[]]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,[5]],[5,-3,[]]]\n5\n
// @lcpr case=end

 */
