/*
 * @lc app=leetcode.cn id=9 lang=javascript
 * @lcpr version=30204
 *
 * [9] 回文数
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
/**
 * @param {number}
 * @return {boolean}
 */
function isPalindrome(x)
{
  var s = x.toString();
  var l = s.length;
  for (var i = 0; i < s.length / 2; i++) {
    if (s[i] != s[l - i - 1]) {
      return false;
    }
  }
  return true;
}
// @lc code=end

/*
// @lcpr case=start
// 121\n
// @lcpr case=end

// @lcpr case=start
// -121\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

 */
