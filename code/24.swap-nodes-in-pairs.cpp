/*
 * @lc app=leetcode.cn id=24 lang=cpp
 * @lcpr version=30204
 *
 * [24] 两两交换链表中的节点
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
        while (it&&it->next&&it->next->next)
        {
            swap(it->next,it->next->next,it);
            it =it->next->next;
        }
        return tmp.next;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
