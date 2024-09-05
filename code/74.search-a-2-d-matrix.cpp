/*
 * @lc app=leetcode.cn id=74 lang=cpp
 * @lcpr version=30204
 *
 * [74] 搜索二维矩阵
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
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int>tmp;
        for(int i = 0;i<matrix.size();i++)
        {
            tmp.push_back(matrix[i][0]);
        }
        auto it = upper_bound(tmp.begin(),tmp.end(),target)-tmp.begin()-1;
        if(it<0||matrix[it][0]>target)
        {
            return false;
        }
        auto ans = lower_bound(matrix[it].begin(),matrix[it].end(),target);
        if(ans == matrix[it].end()||*ans!=target )
        {
            return false;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3\n
// @lcpr case=end

// @lcpr case=start
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n13\n
// @lcpr case=end

 */

