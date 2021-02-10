// 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

// 请你将两个数相加，并以相同形式返回一个表示和的链表。

// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

// 当最后一位有进位怎么办？

 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
   ListNode *preHead = new ListNode(-1);
   ListNode * prev = preHead->next;
   int num1 = 0;
   while (l1 != nullptr && l2 != nullptr){
     // 计算十位
     num1 = (l1->val + l2->val) / 10;
     // 计算个位
     prev->val += (l1->val + l2->val) % 10;
     prev = prev->next;
     if (num1){
       prev->val += num1;
     }
     l1 = l1->next;
     l2 = l2->next;
   }
   // 可能存在进位
   prev->val = (l1 == nullptr) ? l2->val : l1->val;
   prev = prev->next;
   // 如何只将非空指针指向下一个？
   if (l1){
     l1 = l1->next;
     prev->next = l1;
   }else{
     l2 = l2->next;
     prev->next = l2;
   }

   return preHead->next;
 }

 // 如何创建新的数组

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
  ListNode *head = nullptr, *tail = nullptr;
  int carry = 0;
  while (l1 || l2){
    // 有什么作用？
    int n1 = l1 ? l1->val: 0;
    int n2 = l2 ? l2->val: 0;
    int sum = n1 + n2 + carry;
    // 初始节点
    if (!head){
      head = tail = new ListNode(sum % 10);
    }else{
      // 后续节点
      tail->next = new ListNode(sum % 10);
      tail = tail->next;
    }
    carry = sum / 10;
    if (l1){
      l1 = l1->next;
    }
    if (l2){
      l2 = l2->next;
    }
  }
  if (carry > 0){
    tail->next = new ListNode(carry);
  }
  return head;
}