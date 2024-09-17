/*
 * @lc app=leetcode.cn id=92 lang=cpp
 * @lcpr version=30204
 *
 * [92] 反转链表 II
 *
 * https://leetcode.cn/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (56.67%)
 * Likes:    1846
 * Dislikes: 0
 * Total Accepted:    554.3K
 * Total Submissions: 977.5K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right
 * 的链表节点，返回 反转后的链表 。
 *
 *
 * 示例 1：
 *
 * 输入：head = [1,2,3,4,5], left = 2, right = 4
 * 输出：[1,4,3,2,5]
 *
 *
 * 示例 2：
 *
 * 输入：head = [5], left = 1, right = 1
 * 输出：[5]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点数目为 n
 * 1 <= n <= 500
 * -500 <= Node.val <= 500
 * 1 <= left <= right <= n
 *
 *
 *
 *
 * 进阶： 你可以使用一趟扫描完成反转吗？
 *
 */
#define LOCAL 0
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

//   Definition for singly-linked list.
#ifdef LOCAL
struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
#endif
class ListNode;
class Solution
{

public:
	ListNode* reverseBetween(ListNode* head, int left, int right)
	{
		if (left == right)
		{
			return head;
		}
		auto o = head;
		auto preo = new ListNode();
		preo->next = o;
		for (int i = 0; i < left - 1 && preo; i++)
		{
			preo = preo->next;
		}
		if (!preo)
		{
			return head;
		}
		else
		{
			o = preo->next;
			auto tail = o; // pointed by the div
			auto cur = o->next;
			// auto first = o; // point r+1
			// auto div = preo;
			//3 5
			for (int i = 0; i < right - left && cur; i++)
			{
				auto tmp = cur->next;
				cur->next = tail;
				tail = cur;
				cur = tmp;
			}
			o->next = cur;
			preo->next = tail;
			return left == 1?preo->next:head;
		}
	}
};
// @lc code=end

int main(void)
{
	Solution s;
	ListNode* h = new ListNode(1);
	ListNode* h2 = new ListNode(2);
	ListNode* h3 = new ListNode(3);
	ListNode* h4 = new ListNode(4);
	ListNode* h5 = new ListNode(5);
	h->next = h2;
	h2->next = h3;
	h3->next = h4;
	h4->next = h5;
	h = s.reverseBetween(h, 2, 4);
	while (h)
	{
		cout << h->val << "   ";
		h = h->next;
	}
	return 0;
}
/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// [3,5]\n1\n2
// @lcpr case=end

// @lcpr case=start
// [5]\n1\n1\n
// @lcpr case=end

 */
