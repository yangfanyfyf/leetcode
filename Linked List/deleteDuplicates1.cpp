// 存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除所有重复的元素，使每个元素 只出现一次 。

// 返回同样按升序排列的结果链表。

// 和之前那题类似，但是这一题需要保留一个重复的元素

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      if (!head){
        return head;
      }
      ListNode *dummy = new ListNode(0, head);
      ListNode *curr = dummy;
      while (curr->next && curr->next->next){
        if (curr->next->val == curr->next->next->val){
          // 跳过一个点
          curr->next = curr->next->next;
        }else {
          curr = curr->next;
        }
      }
      return dummy->next;
    }
};