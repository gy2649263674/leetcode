
/*
 * @lc app=leetcode.cn id=2502 lang=java
 * @lcpr version=30204
 *
 * [2502] 设计内存分配器
 *
 * https://leetcode.cn/problems/design-memory-allocator/description/
 *
 * algorithms
 * Medium (52.48%)
 * Likes:    48
 * Dislikes: 0
 * Total Accepted:    15.6K
 * Total Submissions: 26K
 * Testcase Example:  '["Allocator","allocate","allocate","allocate","freeMemory","allocate","allocate","allocate","freeMemory","allocate","freeMemory"]\n' +
  '[[10],[1,1],[1,2],[1,3],[2],[3,4],[1,1],[1,1],[1],[10,2],[7]]'
 *
 * 给你一个整数 n ，表示下标从 0 开始的内存数组的大小。所有内存单元开始都是空闲的。
 * 
 * 请你设计一个具备以下功能的内存分配器：
 * 
 * 
 * 分配 一块大小为 size 的连续空闲内存单元并赋 id mID 。
 * 释放 给定 id mID 对应的所有内存单元。
 * 
 * 
 * 注意：
 * 
 * 
 * 多个块可以被分配到同一个 mID 。
 * 你必须释放 mID 对应的所有内存单元，即便这些内存单元被分配在不同的块中。
 * 
 * 
 * 实现 Allocator 类：
 * 
 * 
 * Allocator(int n) 使用一个大小为 n 的内存数组初始化 Allocator 对象。
 * int allocate(int size, int mID) 找出大小为 size 个连续空闲内存单元且位于  最左侧 的块，分配并赋 id mID
 * 。返回块的第一个下标。如果不存在这样的块，返回 -1 。
 * int freeMemory(int mID) 释放 id mID 对应的所有内存单元。返回释放的内存单元数目。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 输入
 * ["Allocator", "allocate", "allocate", "allocate", "freeMemory", "allocate",
 * "allocate", "allocate", "freeMemory", "allocate", "freeMemory"]
 * [[10], [1, 1], [1, 2], [1, 3], [2], [3, 4], [1, 1], [1, 1], [1], [10, 2],
 * [7]]
 * 输出
 * [null, 0, 1, 2, 1, 3, 1, 6, 3, -1, 0]
 * 
 * 解释
 * Allocator loc = new Allocator(10); // 初始化一个大小为 10 的内存数组，所有内存单元都是空闲的。
 * loc.allocate(1, 1); // 最左侧的块的第一个下标是 0 。内存数组变为 [1, , , , , , , , , ]。返回 0 。
 * loc.allocate(1, 2); // 最左侧的块的第一个下标是 1 。内存数组变为 [1,2, , , , , , , , ]。返回 1 。
 * loc.allocate(1, 3); // 最左侧的块的第一个下标是 2 。内存数组变为 [1,2,3, , , , , , , ]。返回 2 。
 * loc.freeMemory(2); // 释放 mID 为 2 的所有内存单元。内存数组变为 [1, ,3, , , , , , , ] 。返回 1
 * ，因为只有 1 个 mID 为 2 的内存单元。
 * loc.allocate(3, 4); // 最左侧的块的第一个下标是 3 。内存数组变为 [1, ,3,4,4,4, , , , ]。返回 3 。
 * loc.allocate(1, 1); // 最左侧的块的第一个下标是 1 。内存数组变为 [1,1,3,4,4,4, , , , ]。返回 1 。
 * loc.allocate(1, 1); // 最左侧的块的第一个下标是 6 。内存数组变为 [1,1,3,4,4,4,1, , , ]。返回 6 。
 * loc.freeMemory(1); // 释放 mID 为 1 的所有内存单元。内存数组变为 [ , ,3,4,4,4, , , , ] 。返回 3
 * ，因为有 3 个 mID 为 1 的内存单元。
 * loc.allocate(10, 2); // 无法找出长度为 10 个连续空闲内存单元的空闲块，所有返回 -1 。
 * loc.freeMemory(7); // 释放 mID 为 7 的所有内存单元。内存数组保持原状，因为不存在 mID 为 7 的内存单元。返回 0
 * 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n, size, mID <= 1000
 * 最多调用 allocate 和 free 方法 1000 次
 * 
 * 
 */ // @lcpr-template-start
// @lcpr-template-end
// @lc code=start
package allocator;

import java.util.*;

class Allocator {

    // ["Allocator", "allocate", "allocate", "allocate", "freeMemory", "allocate", "allocate", "allocate", "freeMemory", "allocate", "freeMemory"]
    // [[10], [1, 1], [1, 2], [1, 3], [2], [3, 4], [1, 1], [1, 1], [1], [10, 2], [7]]
    public static void main(String[] args) {
        Allocator a = new Allocator(10);
        a.allocate(1, 1);
        a.allocate(1, 2);
        a.allocate(1, 3);
        a.freeMemory(2);
        a.allocate(3, 4);
        a.allocate(1, 1);
        a.allocate(1, 1);
        a.freeMemory(1);
        a.allocate(10, 2);
        a.freeMemory(7);
    }
    // Set is the base class of the TreeSet
    // it is ok to assign the sub class to the base class
    // but the base class can only visit the value in the base class 
    // Set<Integer> free1 = new TreeSet<>();
    TreeSet<Integer> free = new TreeSet<>();
    TreeSet<Integer> used = new TreeSet<>();
    HashMap< Integer, ArrayList<Integer>> mid = new HashMap<>();

    // remember the block start with the 
    public Allocator(int n) {
        free.add(0);
        used.add(n);
        // find pos , iter the free and find the smallest value bigger then it in the used
        // to get the cap
    }

    // if is not the smallest one in the used , than should be put in the free 
    // else there is  
    public void mergeFree(Integer l) {
        Integer r = used.ceiling(l);
        // l is the first to be free 
        if (r <= l) {
            return;
        } else {
            free.add(l);
        }
    }

    public void mergeUsed(int l) {

    }

    // when merge add the used to free if there 
    public int allocate(int size, int mID) {
        for (Integer l : free) {
            Integer r = used.ceiling(l);
            if (r - l >= size) {
                // r is usedd can use r-1-l+1 = r-l
                // [left,right)
                // add l to used
                // add l+size to free
                // [l,l+size-1] is used 
                // l to used 
                // l+size is not used or it will be total size+1 
                // used is the [used,n) is used
                free.remove(l);
                mid.get(mID).add(l);
                if (r > l) {
                    // l+size is not used
                    free.add(l + size);
                }
                return size;
            }
        }
        return -1;

    }

    public int freeMemory(int mID) {
        int res = 0;
        for (Integer l : mid.get(mID)) {
            // try to erase from used
            // must be in used
            Integer r = Math.min(free.ceiling(l), used.ceiling(l));
            Integer f = free.ceiling(l);
            Integer u = used.ceiling(l);
            // 
            if (f < u) {
                res += f - l;
                free.add(l);
                free.remove(f);
            } else {
                res += u - l;
                free.add(l);
            }
            // add l to free
        }
        return res;
    }

}
/**
 * Your Allocator object will be instantiated and called as such: Allocator obj
 * = new Allocator(n); int param_1 = obj.allocate(size,mID); int param_2 =
 * obj.freeMemory(mID);
 */
// @lc code=end

