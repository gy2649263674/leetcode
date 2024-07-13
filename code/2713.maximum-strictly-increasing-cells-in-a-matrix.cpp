/*
 * @lc app=leetcode.cn id=2713 lang=cpp
 * @lcpr version=30204
 *
 * [2713] 矩阵中严格递增的单元格数
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

// class Solution
// {
// public:
// 	int m, n; // m row n line
// 	vector<vector<int>> row;
// 	vector<vector<int>> col;
// 	vector<vector<int>> dp;
// 	int re = 0;
// 	void build(vector<vector<int>>& arr)
// 	{
// 		m = arr.size();
// 		n = arr[0].size();
// 		row = vector<vector<int>>(m, vector<int>(n));
// 		col = vector<vector<int>>(m, vector<int>(n));
// 		dp = vector<vector<int>>(m, vector<int>(n, 0));
// 		//col = vector<vector<int>>(n, vector<int>(m));
// 		// mei yi lei de di m ge yuan su neng zhuan yi dao di ji hang
// 		// tong yi lie bianhuan
// 		// to another row
// 		for (int i = 0; i < m; i++)
// 		{
// 			vector<int>tmp(n);
// 			iota(tmp.begin(), tmp.end(), 0);
// 			sort(tmp.begin(), tmp.end(), [&](const int a, const int& b)
// 				{ return
// 				arr[i][a] < arr[i][b];

// 				});
// 			row[i][tmp[n - 1]] = -1;
// 			for (int j = n - 2; j >= 0; j--)
// 			{
// 				//row[i][tmp[j]] = arr[i][tmp[j + 1]] == arr[i][tmp[j]] ? row[i][tmp[j + 1]] : tmp[j + 1];
// 				row[i][tmp[j]] = tmp[j + 1];
// 			}
// 		}
// 		for (int i = 0; i < n; i++)
// 		{
// 			vector<int>tmp(m);
// 			iota(tmp.begin(), tmp.end(), 0);
// 			sort(tmp.begin(), tmp.end(), [&](const int a, const int& b)
// 				{ return arr[a][i] < arr[b][i]; });
// 			col[tmp[m - 1]][i] = -1;
// 			for (int j = m - 2; j >= 0; j--)
// 			{
// 				//col[tmp[j]][i] = arr[tmp[j]][i] == arr[tmp[j + 1]][i]? col[tmp[j+1]][i]:tmp[j+1]; //col[tmp[j + 1]][i];
// 				col[tmp[j]][i] = tmp[j + 1];
// 			}
// 		}
// 		return;
// 	}
// 	int dfs(int x, int y, vector<vector<int>>& arr)
// 	{
// 		if (x < 0 || y < 0)
// 		{
// 			return 0;
// 		}
// 		if (dp[x][y])
// 		{
// 			return dp[x][y];
// 		}
// 		else
// 		{
// 			int nexy = row[x][y];
// 			int tmpy = y;
// 			int ans = 0;
// 			for (int i = 0; nexy != -1; i++)
// 			{
// 				if (arr[x][y] != arr[x][nexy])
// 					ans = max(dfs(x, nexy, arr), ans);
// 				tmpy = nexy;
// 				nexy = row[x][tmpy];
// 			}
// 			nexy = col[x][y];
// 			tmpy = x;
// 			for (int i = 0; nexy != -1; i++)
// 			{
// 				if (arr[x][y] != arr[nexy][y])
// 					ans = max(dfs(nexy, y, arr), ans);
// 				tmpy = nexy;
// 				nexy = col[tmpy][y];
// 			}
// 			return dp[x][y] = ans + 1;
// 		}
// 	}
// 	int maxIncreasingCells(vector<vector<int>>& mat)
// 	{
// 		build(mat);
// 		int ans = 0;
// 		for (int i = 0; i < m; i++)
// 		{
// 			for (int j = 0; j < n; j++)
// 			{
// 				ans = max(dfs(i, j, mat), ans);
// 			}
// 		}
// 		return ans;
// 	}
// };

#define pii pair<int, int>
#include <bits/stdc++.h>
class Solution
{
public:
    int maxIncreasingCells(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        map<int, vector<pii>> mp;
        vector<int> col(n, 0);
        vector<int> row(m, 0);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mp[mat[i][j]].push_back({i, j});
            }
        }
        // 从最小的元素开始,判断是否能从比他小的元素转移过来
        // 从小到大遍历matrix所有最大值均可用
        for (auto &[o, it] : mp)
        {
            vector<int> ex;
            for (auto &pi : it)
            {
                // 一行中的·最大值
                // 共m行
                ex.push_back(max(row[pi.first], col[pi.second]) + 1);
            }
            for (int i = 0; i < it.size(); i++)
            {
                row[it[i].first] = max(row[it[i].first], ex[i]);
                col[it[i].first] = max(col[it[i].second], ex[i]);
                // 一行中的·最大值
            }
        }
        return max(*max_element(row.begin(), row.end()), *max_element(col.begin(), col.end()));
    }
};

// @lc code=end

/*
// @lcpr case=start
// [[3,1],[3,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,1,6],[-9,5,7]]\n
// @lcpr case=end

 */
