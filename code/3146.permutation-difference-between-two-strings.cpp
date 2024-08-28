/*
 * @lc app=leetcode.cn id=3146 lang=cpp
 * @lcpr version=30204
 *
 * [3146] 两个字符串的排列差
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
    int findPermutationDifference(string s, string t) {
        int arr1[26] = {0};
        int arr2[26] = {0};
        for(int i = 0;i<s.length();i++)
        {
                arr1[s[i]-'a'] = i;
                arr2[t[i]-'a'] = i;
        }
        int ans = 0;
        for(int i = 0;i<26;i++)
        {
            ans+= abs(arr1[i]-arr2[i]);
        }
        return ans;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abc"\n"bac"\n
// @lcpr case=end

// @lcpr case=start
// "abcde"\n"edbac"\n
// @lcpr case=end

 */

