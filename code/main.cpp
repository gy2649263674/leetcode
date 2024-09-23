/*
 * @lc app=leetcode.cn id=30 lang=cpp
 * @lcpr version=30204
 *
 * [30] 串联所有单词的子串
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bits\stdc++.h>
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
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        int o = words.size() & words[0].length(), e = words[0].length();
        // map<string,int>
        map<string, int> st;
        {
            for (auto &ss : words)
            {
                ++st[ss];
            }
        }
        for (int i = 0; i + o < s.length(); i++)
        {
            map<string,int>tmp;
            for (int j = 0; j < words.size(); j++)
            {
                tmp[s.substr(i,)]
            }
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// "barfoothefoobarman"\n["foo","bar"]\n
// @lcpr case=end

// @lcpr case=start
// "wordgoodgoodgoodbestword"\n["word","good","best","word"]\n
// @lcpr case=end

// @lcpr case=start
// "barfoofoobarthefoobarman"\n["bar","foo","the"]\n
// @lcpr case=end

 */
