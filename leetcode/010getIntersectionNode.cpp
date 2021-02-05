// 找到两个单链表相交的起始节点

// 使用双指针
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
  if (headA == nullptr || headB == nullptr){
    return nullptr;
  }
  ListNode *p1 = headA;
  ListNode *p2 = headB;
  // 跳出条件，两者都为nullptr
  while (p1 != p2){
    p1 = (p1 ? p1->next : headB);
    p2 = (p2 ? p2->next : headA);
  }
  return p1;





  // if (p1 == p2){
  //   return p1;
  // }

  // if (p1->next == nullptr || p2->next == nullptr){
  //   if (p1 != p2){
  //     return nullptr;
  //   }else{
  //     return p1;
  //   }
  // }
  // while (p1 != p2){
  //   if (p1->next == nullptr && p2->next == nullptr){
  //     if (p1 != p2){
  //       return nullptr;
  //     }
  //   }
  //   if (p1->next == nullptr && p2->next != nullptr){
  //     p1 = headB;
  //   }
  //   if (p1->next != nullptr && p2->next == nullptr){
  //     p2 = headA;
  //   }
  //   p1 = p1->next;
  //   p2 = p2->next;
  //   if (p1 == p2){
  //     return p1;
  //   }
  // }
  // return nullptr;
}





// 遍历所有的节点
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
  if (headA == nullptr || headB == nullptr){
    return nullptr;
  }
  ListNode *p1 = headA;
  ListNode *p2 = headB;
  if (p1 == p2){
    return p1;
  }
  while (p1 != nullptr){
    p2 = headB;
    while(p2 != nullptr){
      if (p1 == p2){
        return p1;
      }
      p2 = p2->next;
    }
    p1 = p1->next;
  }
  return nullptr;
}