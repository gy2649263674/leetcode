#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin>>n;
        vector<int> arr;
        while (n--)
        {
            int val;
            cin >> val;
            arr.push_back(val);
        }
        if(arr[0]!=arr[1])
        {
            cout<<(arr[1]== arr[2]?1:2)<<endl;
            continue;
        }
        for(int i = 0;i<n-1;i++)
        {
            if(arr[i]!=arr[i+1])
            {
                cout<<i+2<<endl;
                break;
            }
        }
    }
    system("pause");
    return 0;
}