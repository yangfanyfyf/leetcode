// 删除链表中等于给定值 val 的所有节点

// 遍历？
ListNode* removeElements(ListNode* head, int val){
  if (head == nullptr){
    return nullptr;
  }
  ListNode *p = head;
  // 删除节点时有一个问题，我可以找到一个指定的位置，但是我删除这个节点我
  // 需要之前的那个节点
  // 笨方法，先找到位置，再重新遍历d得到这个点之前的节点
  // 仅可用于两个节点以上的

  while (p != nullptr){
    if (p->val == val){
      ListNode *temp = head;
      while (temp->next != p){
        temp = temp->next;
      }
      // 跳过
      temp->next = temp->next->next;
    }
    p = p->next;
  }
  return head;
}

// 通过设置哨兵节点，和前后两个节点，来解决这个问题

ListNode* removeElements(ListNode* head, int val){
  if (head == nullptr){
    return nullptr;
  }
  ListNode *sentinal = new ListNode(0);
  sentinal->next = head;
  
  ListNode *prev = sentinal, *curr = head, *toDelete = nullptr;

  while(curr != nullptr){
    if(curr->val == val){
      prev->next = curr->next;
      toDelete = curr;
    }else{
      prev = curr;
    }
    curr = curr->next;

    if (toDelete != nullptr){
      delete toDelete;
      toDelete = nullptr;
    }
  }
    ListNode *ret = sentinal->next;
    delete sentinal;
    sentinal = nullptr;
    return ret;
  
}