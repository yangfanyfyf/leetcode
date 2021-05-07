// 给你一个链表数组，每个链表都已经按升序排列。

// 请你将所有链表合并到一个升序链表中，返回合并后的链表。

// 每次合并两个，依次执行
class Solution {
public:
    ListNode* merge2Lists(ListNode *l1, ListNode *l2){
      if (!l1 || !l2){
        return l1 ? l1 : l2;
      }
      ListNode *dummyHead = new ListNode(-1), *tail = dummyHead, *ptr1 = l1, *ptr2 = l2;
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      ListNode *ans = nullptr;
      for (auto &p : lists){
        ans = merge2Lists(ans, p);
      }
      return ans;
    }
};