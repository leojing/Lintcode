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










# 资料
- https://techiedelight.quora.com/500-Data-Structures-and-Algorithms-interview-questions-and-their-solutions
