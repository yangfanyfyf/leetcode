// 删除链表的倒数第 n 个结点，并且返回链表的头结点

// 双节点，两个节点之间相差n-1
ListNode* removeNthFromEnd(ListNode* head, int n){
  if (head == nullptr){
    return nullptr;
  }
  ListNode *p1 = head;
  ListNode *p2 = head;
  // 移动p2
  while (n){
    if (p2 == nullptr) return nullptr;
    p2 = p2->next;
    --n;
  }
  while (p2 != nullptr){
    p1 = p1->next;
    p2 = p2->next;
  }
  // 去除p1指向的元素即可
  ListNode *p3 = head;
  while (p3->next != p1 && p3->next != nullptr){
    p3 = p3->next;
  }
  p3->next = p1->next;
  delete p1;
}


ListNode* removeNthFromEnd(ListNode* head, int n){
  ListNode *dummy = new ListNode(0, head);
  ListNode *first = head;
  ListNode *second = dummy;
  while (n){
    if (first == nullptr) return head;
    first= first->next;
    --n;
  }
  while (frist){
    first = first->next;
    second = second->next;
  }
  second->next = second->next->next;
  ListNode *ret = dummy->next;
  delete dummy;
  return ret;
}