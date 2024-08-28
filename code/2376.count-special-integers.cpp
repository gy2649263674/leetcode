///*
// * @lc app=leetcode.cn id=698 lang=cpp
// * @lcpr version=30204
// *
// * [698] 划分为k个相等的子集
// */
//
// // @lcpr-template-start
// /*
//  * @lc app=leetcode.cn id=698 lang=cpp
//  * @lcpr version=30204
//  *
//  * [698] 划分为k个相等的子集
//  */
//
//  // @lcpr-template-start
//using namespace std;
//#include <algorithm>
//#include <array>
//#include <bitset>
//#include <climits>
//#include <deque>
//#include <functional>
//#include <iostream>
//#include <list>
//#include <queue>
//#include <stack>
//#include <tuple>
//#include <unordered_set>
//#include <utility>
//#include <vector>
//#include "e:\zzs\gy\cpp\stdc++.h"
//
//// @lcpr-template-end
//// @lc code=start
///*
// * @lc app=leetcode.cn id=698 lang=cpp
// * @lcpr version=30204
// *
// * [698] 划分为k个相等的子集
// */
//
// // @lcpr-template-start
// /*
//  * @lc app=leetcode.cn id=698 lang=cpp
//  * @lcpr version=30204
//  *
//  * [698] 划分为k个相等的子集
//  */
//
////  // @lcpr-template-start
////using namespace std;
////#include <algorithm>
////#include <array>
////#include <bitset>
////#include <climits>
////#include <deque>
////#include <functional>
////#include <iostream>
////#include <list>
////#include <queue>
////#include <stack>
////#include <tuple>
////#include <unordered_set>
////#include <utility>
////#include <vector>
////#include "e:\zzs\gy\cpp\stdc++.h"
////#include<set>
////// @lcpr-template-end
////// @lc code=start
////class solution
////{
////public:
////bool state[1 << 10] = { false };
////vector<int> s[1 << 10];
////	int tarl = 0, tarn, q;
////	bool dfs(int sta, int n, int pre, vector<int>& nums)
////	{
////		s[sta].push_back(pre);
////		if (sta == 0)
////		{
////			return false;
////		}
////		//if (state[sta])
////		//{
////		//	return false;
////		//}
////		state[sta] = true;
////		bool ans = false;
////		for (int i = 0; i < nums.size(); i++)
////		{
////			if (nums[i] + pre > tarl)
////			{
////				break;
////			}
////			if ((sta & (1 << i)))
////			{
////				q = ~(1 << i);
////				ans |= dfs(sta ^ (1 << i), n, (pre + nums[i]) % tarl, nums);
////				if (!ans)
////				{
////					i = nex[i];
////				}
////				else
////				{
////					return true;
////				}
////				// if (pre == 0 && ans == false)
////				// {
////				// 	return false;
////				// }
////			}
////		}
////		return ans;
////	}
////	int nex[20];
////	bool canpartitionksubsets(vector<int> nums, int k)
////	{
////		sort(nums.begin(), nums.end());
////		int next = nums.size() - 1;
////		for (int i = nums.size() - 1; i >= 1; i--)
////		{
////			nex[i] = next;
////			if (nums[i - 1] != nums[i])
////			{
////				next = i - 1;
////			}
////		}
////		nex[0] = nums[1] == nums[0] ? nex[1] : 0;
////		tarn = k;
////		tarl = accumulate(nums.begin(), nums.end(), tarl);
////		if (tarl % k)
////		{
////			return false;
////		}
////		tarl /= k;
////		if (nums.back() > tarl)
////		{
////			return false;
////		}
////		 dfs(-1 + (1 << nums.size()), 0, 0, nums);
////		 for (int i = 0; i < -1 + (1 << nums.size()); i++)
////		 {
////			 for (int var : s[i])
////			 {
////				 cout << var << " ";
////			 }
////			 cout << endl;
////		 }
////		 return true;
////
////	}
////};
////
////
////
////
/////*
////// @lcpr case=start
////// [4, 3, 2, 3, 5, 2, 1]\n4\n
////// @lcpr case=end
////
////// @lcpr case=start
////// [1,2,3,4]\n3\n
////// @lcpr case=end
////
//// */
////
////
////// @lc code=end
////int main(void)
////{
////	const char* str = "dasd";
////	char ss[10] = "dasd";
////	cout << ss;
////	return 0;
////
////	solution s;
////	cout << s.canpartitionksubsets({ 1,2,3,4,5,2,3 }, 4);
////	return 0;
////
////}
////
/////*
////// @lcpr case=start
////// [4, 3, 2, 3, 5, 2, 1]\n4\n
////// @lcpr case=end
////
////// @lcpr case=start
////// [1,2,3,4]\n3\n
////// @lcpr case=end
////
//// */
////
//
///*
// * @lc app=leetcode.cn id=3144 lang=cpp
// * @lcpr version=30204
// *
// * [3144] 分割字符频率相等的最少子字符串
// */
//
// // @lcpr-template-start
//using namespace std;
//#include <algorithm>
//#include <array>
//#include <bitset>
//#include <climits>
//#include <deque>
//#include <functional>
//#include <iostream>
//#include <list>
//#include <queue>
//#include <stack>
//#include <tuple>
//#include <unordered_map>
//#include <unordered_set>
//#include <utility>
//#include <vector>
////#include <bits/stdc++.h>
//// @lcpr-template-end
//// @lc code=start
//string ss;
//class Solution
//{
//public:
//    int minimumSubstringsInPartition(string s)
//    {
//        //ss = s;
//        int pre[1001][26];
//        memset(pre[0], 0, sizeof(pre));
//        // self and don't include pre
//        for (int i = 1; i <= s.length(); i++)
//        {
//            for (int j = 0; j < 26; j++)
//            {
//                pre[i][j] = pre[i - 1][j] + (s[i - 1] == 'a' + j ? 1 : 0);
//                // the i st char0
//            }
//        }
//        int dp[1001] = {0};
//        function<bool(int, int)> check = [&](int p, int s) -> bool
//            {
//                vector<int> tmp;
//                for (int i = 0; i < 26; i++)
//                {
//                    int c = pre[s][i] - pre[p][i];
//                    //ignore p self
//                    if (!tmp.empty() && c != tmp.back()&&c!= 0)
//                    {
//                        return false;
//                    }
//                    if (c)
//                    {
//                        tmp.push_back(c);
//                    }
//                }
//                return true;
//            };
//        function<int(int)> f = [&](int cur) -> int
//            {
//				if (cur == 0)
//				{
//					return 0;
//				}
//                if (cur == 1)
//                {
//                    return 1;
//                }
//                if (dp[cur] != 0)
//                {
//                    return dp[cur];
//                }
//                int ans = 1e9;
//                for (int i = 0; i<= cur-1; i++)
//                {
//                    // i is used
//                    if (check(i, cur))
//                    {
//                        ans = min(f(i)+1, ans);
//                    }
//                }
//                return dp[cur] = ans;
//            };
//        return f(s.length());
//    }
//};
//// @lc code=end
//int main(void)
//{
//    Solution s;
//    cout << s.minimumSubstringsInPartition("kdeebsigsshzggggggwwnnaasyxrywywywvvwffffgxknlimimukkgeedlkmnlmpkkglrqphzzytpqryztsaazinknnklnbedgcczfffzzzycllqqqhhajnukkdmyzuvubsrmmmqaoonnmmbbbbllltcfdbeeeadazpppppcxxtdizsdddgkrreinnnqrqqqkkbhklltisccnrstuiqqbaaaustsirqqllttjiyyyyupbnnmmkkhbcodtvyyyjovvjijiwwwwmmlkljavvwijjzzjxpppynppmlsscbioccczzqqqhtntyrkkkkkkcccllaqqnkrwssfhvvvpdlvwvooggxxdetoooiyzjffoociiggggfqpmylddgyxdltuueeylmeeeggfzzekktkbbyynvstucnpnvvvnwrsgghmixyxyjjuuuannnnozovxmfettxiopninyzyxcccczvnzghiyyqookfyyjjjiigjzjjooiiitiocijquwwwwuqeqodqqrpffeppoyykkfwoddddddgfffispzmrrrqprpmlllttmmffempppdmwwjkelgkmkjmsmewwwsciimfvuxttleefhyyvdvvoooicmmmstllllmmbrawwvbbeefckkkrrwxnppaluvpittjquwvxwttuvsdrvvrwwcqqplldcheegrqvvthicyavrddhxxhpooxujwxswrnyxxxxxvvfkgggguiiitthhxtwuxulllllllllcsqqqrrrpgwqurbatqqqrrrrrpqrqpptaiiikociqeeggsokjxxenoaauujjjcdpvvxrgpppuuvulleeeeddddnnzlwwyyywaabbjcccrjjoymdddddxqpinnobffyiowqaawxyzybwhgvrohhhvzzzzdvsprosqonxgkxlmmwwruqoqmeuutiihsvgffffutyywtvbammofrssrlamgqqrxbbuutvvrvvtwzgfgvveddikkagg");
//    return 0;
//}
///*
//// @lcpr case=start
//// "fabccddg"\n
//// @lcpr case=end
//
//// @lcpr case=start
//// "abababaccddb"\n
//// @lcpr case=end
//
// */
