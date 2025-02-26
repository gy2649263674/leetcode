#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};
template <typename T>
ostream &operator<<(ostream &out, vector<T> vec)
{
    for (auto &i : vec)
    {
        out << i << " ";
    }
    return out;
}
void dfs()
{
}
int main(void)
{
    int N = 100, T = 1000;
    while (T--)
    {
        vector<int> arr(N);
        iota(arr.begin(), arr.end(), 0);
        srand(time(0));
        int l = rand();
        int r = rand();
        while (r == l)
        {
            r = rand();
            /* code */
        }
        swap(arr[l], arr[r]);
        int l1 = 0, l2 = 0;
        // cout << arr << endl;
        for (int i = 0; i + 1 < arr.size(); i++)
        {
            if (arr[i] > arr[i + 1])
            {
                if (l1 == 0)
                {
                    l1 = i;
                }
                else
                {
                    l2 = i + 1;
                    break;
                }
            }
        }
        swap(arr[l1], arr[l2]);
        // cout << arr << endl;
        cout << is_sorted(arr.begin(), arr.end()) << endl;
        if (!is_sorted(arr.begin(), arr.end()))
        {
            cout << "Error" << endl;
            break;
        }
    }
    return 0;
}