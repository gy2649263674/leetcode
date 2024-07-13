/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
using namespace std;
class Solution
{
public:
    int dif(const string &a, const string &b)
    {
        int cnt = 0;
        for (int i = 0; i < a.length(); i++)
        {
            cnt += a[i] != b[i];
        }
        return cnt;
    }
    int bfs(string cur, string &tar, vector<string> &vec)
    {
        // sort(vec.begin(), vec.end(), [&](const string &a, const string &b)
        //    { return dif(a, tar) < dif(b, tar); });
        // bool *vis = new bool[vec.size()];
        // unordered_map<string, bool> vis;
        vector<bool> vis(vec.size());
        vec.push_back(cur);
        queue<int> aux;
        aux.push(vec.size() - 1);
        int cnt = 0;
        while (aux.empty() == false)
        {
            ++cnt;
            int j = aux.size();
            for (int i = 0; i < j; i++)
            {
                for (int l = 0; l < vec.size() - 1; l++)
                {
                    if (dif(vec[l], vec[aux.front()]) == 1 && vis[l] == false)
                    {
                        if (vec[l] == tar)
                        {
                            return ++cnt;
                        }
                        aux.push(l);
                        vis[l] = true;
                    }
                }
                aux.pop();
            }
        }
        return 0;
    }
    int ladderLength(string be, string en, vector<string> &dic)
    {
        return bfs(be, en, dic);
    }
};
// @lc code=end
// int main(void)
// {
//     Solution s;
//     vector<string>v{"hot", "dot", "dog", "lot", "log", "cog"};
//     s.ladderLength("hit", "cog", v);
//     return 0;
// }