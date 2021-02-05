// 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null
// 

ListNode *detectCycle(ListNode *head){
  if (head == nullptr || head->next == nullptr){
    return nullptr;
  }
  ListNode *slow = head;
  ListNode *fast = head;
  while(fast != nullptr){
    slow = slow->next;
    if (fast->next == nullptr){
      return nullptr;
    }
    fast = fast->next->next;
    if (fast == slow){
      ListNode *ptr = head;
      while (ptr != slow){
        ptr = ptr->next;
        slow = slow->next;
      }
      return ptr;
    }
  }
  return nullptr;
}