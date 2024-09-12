/*
 * @lc app=leetcode.cn id=2181 lang=cpp
 * @lcpr version=30204
 *
 * [2181] 合并零之间的节点
 *
 * https://leetcode.cn/problems/merge-nodes-in-between-zeros/description/
 *
 * algorithms
 * Medium (84.11%)
 * Likes:    37
 * Dislikes: 0
 * Total Accepted:    20.2K
 * Total Submissions: 23.8K
 * Testcase Example:  '[0,3,1,0,4,5,2,0]'
 *
 * 给你一个链表的头节点 head ，该链表包含由 0 分隔开的一连串整数。链表的 开端 和 末尾 的节点都满足 Node.val == 0 。
 *
 * 对于每两个相邻的 0 ，请你将它们之间的所有节点合并成一个节点，其值是所有已合并节点的值之和。然后将所有 0 移除，修改后的链表不应该含有任何 0
 * 。
 *
 * 返回修改后链表的头节点 head 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [0,3,1,0,4,5,2,0]
 * 输出：[4,11]
 * 解释：
 * 上图表示输入的链表。修改后的链表包含：
 * - 标记为绿色的节点之和：3 + 1 = 4
 * - 标记为红色的节点之和：4 + 5 + 2 = 11
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [0,1,0,3,0,2,2,0]
 * 输出：[1,3,4]
 * 解释：
 * 上图表示输入的链表。修改后的链表包含：
 * - 标记为绿色的节点之和：1 = 1
 * - 标记为红色的节点之和：3 = 3
 * - 标记为黄色的节点之和：2 + 2 = 4
 *
 *
 *
 *
 * 提示：
 *
 *
 * 列表中的节点数目在范围 [3, 2 * 10^5] 内
 * 0 <= Node.val <= 1000
 * 不 存在连续两个 Node.val == 0 的节点
 * 链表的 开端 和 末尾 节点都满足 Node.val == 0
 *
 *
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
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *nh = new ListNode(0);
        auto o = nh, tail = nh;
        int tmp = 0;
        do
        {
            head = head->next;
            if (head && head->val != 0)
            {
                int tmp = 0;
                while (head && head->val)
                {
                    tmp += head->val;
                    head = head->next;
                }
                if (tmp)
                {
                    tail->val = tmp;
                    tail->next = new ListNode(0);
                    tail = tail->next;
                }
            }

        } while (head);
        if (tail->val == 0)
        {
            auto tmp = nh;
            while (tmp->next != tail)
            {
                tmp = tmp->next;
            }
            tmp->next = NULL;
            delete tail;
        }
        return nh;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [0,3,1,0,4,5,2,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,3,0,2,2,0]\n
// @lcpr case=end

 */
