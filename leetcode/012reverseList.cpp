// 反转一个单链表
// 每次将一个位置的节点移到最前面

ListNode* reverseList(ListNode* head){
  if (head == nullptr || head->next == nullptr){
    return head;
  }
  ListNode *first = head;
  ListNode *temp;
  while (first->next != nullptr){
    // next->next可能是nullptr?
    temp = first->next;
    first->next = first->next->next;
    temp->next = head;
    head = temp;
  }
  return head;
}