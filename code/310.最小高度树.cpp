/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @lc code=start
class Solution
{
public:
	// int dfs(int root)
	// {
	//     vis[root] = 1;
	//     int val = 0;
	//     int index = root;
	//     for (int var : mp[root])
	//     {
	//         if (vis[var] == false)
	//         {
	//             par[var] = root;
	//             vis[var] = 1;
	//             if ()
	//         }
	//     }
	// }
	vector<int> par;
	int bfs(int root)
	{
		vector<bool> vis(par.size());
		queue<int> aux;
		aux.push(root);
		int cur = root;
		while (!aux.empty())
		{
			cur = aux.front();
			vis[cur] = true;
			cur = aux.front();
			for (int var : mp[cur])
			{
				if (vis[var] == false)
				{
					vis[var] = true;
					par[var] = cur;
					aux.push(var);
				}
			}
			aux.pop();
		}
		return cur;
	}
	vector<vector<int>> mp;
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
	{
		mp.resize(n);
		par.resize(n);
		for (auto var : edges)
		{
			mp[var[0]].push_back(var[1]);
			mp[var[1]].push_back(var[0]);
		}
		int ori = bfs(0);
		int far = bfs(ori);
		par[ori] = -1;
		vector<int> path;
		int maxdis = 0;
		while (far>=0)
		{
			path.push_back(far);
			far = par[far];
			++maxdis;
		}
		if (maxdis & 1)
		{
			//  return vector<int>{path[maxdis / 2], path[maxdis / 2 + 1]};
			return vector<int>{path[maxdis / 2]};
		}
		else
		{
			return vector<int>{path[maxdis / 2], path[maxdis / 2 -1]};
		}
	}
};
// @lc code=end
