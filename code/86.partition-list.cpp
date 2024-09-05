/*
 * @lc app=leetcode.cn id=86 lang=cpp
 * @lcpr version=30204
 *
 * [86] 分隔链表
 */

#define LOCAL
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

// Definition for singly-linked list.
#ifdef LOCAL
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        auto o = head;
        auto newhead = new ListNode();
        auto res = newhead;
        while (head)
        {
            if (head->val < x)
            {
                newhead->next = new ListNode(head->val);
                newhead = newhead->next;
            }
            head = head->next;
        }
        head = o;
        while (head)
        {
            if (head->val >= x)
            {
                newhead->next = new ListNode(head->val);
                newhead = newhead->next;
            }
            head = head->next;
        }
        return res->next;
        auto l = head, r = head;
        while (r != NULL)
        {
            if (r->val < x)
            {
                swap(l->val, r->val);
                l = l->next;
            }
            r = r->next;
        }
        return head;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,4,3,2,5,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n2\n
// @lcpr case=end

 */
