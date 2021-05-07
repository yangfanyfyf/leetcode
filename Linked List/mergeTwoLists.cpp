// 将两个升序链表合并为一个新的 升序 链表并返回。

// 新链表是通过拼接给定的两个链表的所有节点组成的。 

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      if (!l1 || !l2){
        return l1 ? l1 : l2;
      }
      ListNode *dummyHead = new ListNode(-1);
      ListNode *tail = dummyHead, *ptr1 = l1, *ptr2 = l2;
      while (ptr1 && ptr2){
        if (ptr1->val < ptr2->val){
          tail->next = ptr1;
          ptr1 = ptr1->next;
        }else {
          tail->next = ptr2;
          ptr2 = ptr2->next;
        }
        tail = tail->next;
      }
      tail->next = (ptr1 ? ptr1 : ptr2);
      return dummyHead->next;

    }
};