/*
 * @lc app=leetcode.cn id=25 lang=cpp
 * @lcpr version=30204
 *
 * [25] K 个一组翻转链表
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    void swap(ListNode *pre, ListNode *suf, ListNode *head)
    {
        if (pre && suf)
        {
            auto it = suf->next;
            pre->next = it;
            suf->next = pre;
            head->next = suf;
        }
        return;
    }
    ListNode *swapPairs(ListNode *head)
    {
        ListNode tmp;
        tmp.next = head;
        auto it = &tmp;
        while (it && it->next && it->next->next)
        {
            swap(it->next, it->next->next, it);
            it = it->next->next;
        }
        return tmp.next;
    }
    bool move(ListNode *a, int k)
    {
        while (a && k--)
        {
            a = a->next;
        }
        return a == NULL;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *tmp = new ListNode;
        tmp->next = head;
        auto pre = tmp;
        auto nowpre = pre;
        while (pre)
        {
            if (move(pre, k))
            {
                break;
            }
            for (int i = 0; i < k; i++)
            {
                pre = nowpre;
                for (int j = 0; j < k - i - 1; j++)
                {
                    swap(pre->next, pre->next->next, pre);
                    pre = pre->next;
                }
            }
            int T = k;
            while (nowpre && T--)
            {
                nowpre = nowpre->next;
            }
            pre = nowpre;
        }
        return tmp->next;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n3\n
// @lcpr case=end

 */
