//#include <bits/stdc++.h>
using namespace std;
using namespace std;
int arr[26][100000] = { 0 };

class Solution
{
public:
	// map<string, bool, decltype(comp)> mp(comp);
	class Tries
	{
	public:
		///vector<map<int, int>> arr;
		Tries()
		{
			//arr.resize(26);
		}
		int cnt = 0;
		void insert(string& s)
		{
			int now = 0;
			for (int i = s.length() - 1; i >= 0; i--)
			{
				if (arr[now][s[i] - 'a'] == 0)
				{
					arr[now][s[i] - 'a'] = ++cnt;
					now = cnt;
				}
				else
				{
					now = arr[now][s[i] - 'a'];
				}
			}
			return;
		}
		int getlength(int floor, int  s)
		{
			if (arr[floor][s] == 0)
			{
				return 0;
			}
			int sum = 0;
			int nex = arr[floor][s];
			if (nex == 1)
			{
				return 0;
			}
			int flag = 0;
			for (int i = 0; i < 26; i++)
			{
				if (arr[nex][i] != 0)
				{
					flag = 1;
					sum += getlength(nex, i) + 1;
				}
			}
			return flag?sum:1;
		}
	};
	int violet(vector<string>& dic)
	{
		auto comp = [](const string& a, const string& b) -> bool
			{
				return a.length() > b.length();
			};
		// multiset<string, decltype(comp)> mp(comp);
		//		map<>
		set<string> mp;
		sort(dic.begin(), dic.end(), comp);
		for (auto& it : dic)
		{
			mp.insert(it);
		}
		string ans;
		int n = dic.size();
		int num = 0;
		for (string& it : dic)
		{
			if (mp.count(it) == 1)
			{
				++num;
				ans += it;
				for (int i = 0; i < it.length(); i++)
				{
					if (mp.count(it.substr(i, it.length() - i)))
					{
						mp.erase(it.substr(i, it.length() - i));
					}
				}
			}
		}
		return ans.length() + num;
	}

	int
		minimumLengthEncoding(vector<string>& words)
	{
		Tries t;
		for (auto& it : words)
		{
			t.insert(it);
		}
		int ans = 0;
		for (int i = 0; i < 26; i++)
		{
			ans += t.getlength(0, i);
		}
		return ans;
	}
};
// @lc code=end
int main()
{
	Solution s;
	vector<string> words = { "time", "me", "bell" };
	cout << s.minimumLengthEncoding(words) << endl;
	return 0;
}

// @lc code=end
