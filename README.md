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
