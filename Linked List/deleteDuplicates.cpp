// 存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除链表中所有存在数字重复情况的节点，只保留原始链表中 没有重复出现 的数字。

// 返回同样按升序排列的结果链表。



// 作者：liweiwei1419
// 链接：https://leetcode-cn.com/leetbook/read/learning-algorithms-with-leetcode/erezad/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      if (!head){
        return nullptr;
      }
      ListNode *dummyHead = new ListNode(-1);
      dummyHead->next = head;
      ListNode *cur = dummyHead;
      while (cur->next && cur->next->next){
        if (cur->next->val == cur->next->next->val){
          int x = cur->next->val;
          while (cur->next && cur->next->val == x){
            cur->next = cur->next->next;
          }
        }else {
          cur = cur->next;
        }
      }
      return dummyHead->next;
    }
};