// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

// 将第二个链表中的节点插入L1？？？
// 还是新建一个空的链表？
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
  if (l1 == nullptr && l2 == nullptr ){
    return nullptr;
  }else if(l1 == nullptr && l2 != nullptr){
    return l2;
  }
  // p1 是插入的位置，p2指示当前位置
  ListNode *p1 = l1;
  ListNode *p2 = l2;
  while (p2 != nullptr){
    // 向前加，只要p1前面就可以
    if(p2->val < p1->val){
      l2 = l2->next;
      p2->next = p1;
      // 将p2重新指向l2
      l1 = p2;
      p2 = l2;
    }else{
      if (p1->next && p1->next->val < p2->val) {
        p1 = p1->next;
        continue;
      }
      l2 = l2->next;
      p2->next = p1->next;
      p1->next = p2;
      p1 = p1->next;
      p2 = l2;
    }
  }
  return l1;
}


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
  ListNode *preHead = new ListNode(-1);

  ListNode* prev = preHead;

  while (l1 != nullptr && l2 != nullptr){
    if (l1->val < l2->val){
      prev->next = l1;
      l1 = l1->next;
    }else{
      prev->next = l2;
      l2 = l2->next;
    }
    prev = prev->next;
  }
  prev->next = (l1 == nullptr) ? l2 : l1;

  return preHead->next;
}