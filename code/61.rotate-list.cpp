/*
 * @lc app=leetcode.cn id=61 lang=cpp
 * @lcpr version=30204
 *
 * [61] 旋转链表
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
/**
 * Definition for singly-linked list.

 */
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
struct ListNode;
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if(head == NULL)
        {
            return NULL;
        }
        function<int(ListNode *)> getlen = [&](ListNode *head) -> int
        {
            int res = 0;
            auto o = head;
            while (o)
            {
                o = o->next;
                ++res;
            }
            return res;
        };
        function<ListNode *(int, ListNode *head)> get_kth = [](int k, ListNode *head) -> ListNode *
        {
            int res = 0;
            while (k--)
            {
                head = head->next;
                ++res;
            }
            return head;
        };
        int len = getlen(head);
        k %= len;
        if (k == 0)
        {
            return head;
        }
        auto newend = get_kth(len-k-1, head);
        auto newhead = newend->next;
        auto link = get_kth(len-1,head);
        link->next = head;
        newend->next = NULL;
        return newhead;
    };
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2]\n4\n
// @lcpr case=end

 */
