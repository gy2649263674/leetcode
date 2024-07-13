#include<map>
void AddTomap(int a)
{
	

}
int  check(map<int, set<int>>s, int a, int b)
{
	if (s[a].count(b))
	{
		return 1;
	}
	else
	{
		for (int var : s[a])
			check(s, var, b);
	}
}
int main(void)
{
	int n;
	cin >> n;
	//queue<>
	set<pair<int, int>>* store = new set<pair<int, int>>;;
	int root = 0;
	//map<int ,pair<int,int>>
	map<int,set<int>>te;
	for (int i = 0; i < n; i++)
	{
		pair<int, int>temp;
		scanf("%d%d", temp.first, temp.second);
		if (temp.first > temp.second)
		{
			swap(temp.first, temp.second);
		}
		if (temp.second == -1)
		{
			root = temp.first;
		}
		te[temp.first].insert(temp.second);
		te[temp.second].insert(temp.first);
	}
	map<int, set<int>>query;
	queue<int> auxiliary;
	while (!auxiliary.empty())
	{
		int cur = auxiliary.front();
		auxiliary.pop();
		for (int var : te[cur])
		{
			query[cur].insert(var);
			auxiliary.push(var);
		}
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
	}
}
