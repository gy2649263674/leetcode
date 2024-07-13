/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// struct ListNode;

class Solution
{
public:
    ListNode *merge2(ListNode *p1, ListNode *p2)
    {
        ListNode ans;
        ListNode *p3 = &ans;
        while (p1 && p2)
        {
            if (p1->val < p2->val)
            {
                p3->next = p1;
                p1 = p1->next;
            }
            else
            {
                p3->next = p2;
                p2 = p2->next;
            }
            p3 = p3->next;
        }
        p3->next = p1 ? p1 : p2;
        return ans.next;
    }
    ListNode *solve(int l, int r, vector<ListNode *> &lists)
    {
        if (l > r)
        {
            return NULL;
        }
        if (l == r)
        {
            return lists[l];
        }
        ListNode *p1;
        ListNode *p2;
        p1 = solve(l, (l + r) >> 1, lists);
        p2 = solve((l + r) / 2 + 1, r, lists);
        return merge2(p1, p2);
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return solve(0, lists.size() - 1, lists);
    }
};
// @lc code=end
