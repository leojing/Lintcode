# Lintcode
- 7- binary tree, 非递归写法，queue，stack
- 423- Valid Parentheses，利用stack先进后出，push左括号，如果碰到匹配的右括号，即pop, 最后没有剩余即为vaild
- 427- Gengrate Parentheses，DFS 穷举所有有效括号的排列方法
- 12- Min stack，模拟stack，关键是要有2个stack，一个模拟，一个存放最小值
- 471- 获取前k个最高频词汇，用map记录下词汇量，放入vector中进行排序，关键要重写vector的compare函数
- 104- Merge K Sorted Lists:
  - Soultion 1:
       二分法，将list不断拆分为2个list进行merge，最后list中剩余2个item的时候进行两两merge
  - Soultion 2:
       将所有ListNode中的node取出存入priority_queue，进行排序后组建成新的ListNode
- 486- 和104一样
- 577- Merge K Sorted Interval Lists
  - 也可用二分法，和104，486类似。
  - 本题若用priority_queue解法，关键在于使用tuple进行二维数组操作。
- 88- Lowest Common Ancestor in a Binary Tree—Using Single Traversal
  - The method 1 finds LCA in O(n) time, but requires three tree traversals plus extra spaces for path arrays. If we assume that the keys n1 and n2 are present in Binary Tree, we can find LCA using single traversal of Binary Tree and without extra storage for path arrays.
  - The idea is to traverse the tree starting from root. If any of the given keys(n1 and n2) matches with root, then root is LCA (assuming that both keys are present). If root doesn’t match with any of the keys, we recur for left and right subtree. The node which has one key present in its left subtree and the other key present in right subtree is the LCA. If both keys lie in left subtree, then left subtree has LCA also, otherwise LCA lies in right subtree.
- 223- LinkedList 回文判断
  - 时间复杂度O(n)-准确说是O(n/2), 根据大O计算法则就是O(n)，找中间节点的、反转、对比都是O(n/2)。
  - 空间复杂度O(1), 没有开辟任何新内存空间，都是基于本身的ListNode进行的操作。
  - 1，寻找中间节点，fast指针走两步，slow指针走一步
  - 2，将后半部分反转
  - 3，对比前后半部分ListNode，一样就返回true
- 102- LinkedList cycle，Solution without using extra space:
  - 这个思路太巧妙了，用2个指针，一快（走2步）一慢（走y1步）去走，如果没有loop，则两者永远不会碰到，到结尾时返回false，如果有loop，两个指针必定会在某个节点遇到，则返回true。
  - 难点：还没想明白为什么一个走1步，一个走2步必定会遇到对方，如果是一个走1步，一个走3步，还能成立嘛？这个算数学思考，和hk讨论后，觉得是只要一快一慢，不管几步，总能遇见对方^_^
- 69- Binary Tree Level Order Traversal
  - Solution 1:
  - BFS：二叉树的层次遍历通过队列来进行，先将root进队，进入循环。判断队列是否为空，记录size为队列中元素的个数，表示这一层级有多少个元素，不为空将此时队列中的元素一个一个出队，同时将子女入队。这样每次出队的元素都为一个层次中的。
  - Solution 2:
  - DFS: 未实现






# 资料
- https://techiedelight.quora.com/500-Data-Structures-and-Algorithms-interview-questions-and-their-solutions
- https://www.geeksforgeeks.org/must-do-coding-questions-for-companies-like-amazon-microsoft-adobe/
- http://fisherlei.blogspot.com/search/label/hash
- http://www.1point3acres.com/bbs/thread-441415-1-1.html
