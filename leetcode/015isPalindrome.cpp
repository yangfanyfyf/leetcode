// 请判断一个链表是否为回文链表。


// 先将链表反转？
// 反转一半的链表
// 使用快慢指针
bool isPalindrome(ListNode* head){
  if (head == nullptr || head->next == nullptr){
    return true;
  }
  ListNode *slow = head, *fast = head->next;
  while(fast != nullptr && fast->next != nullptr){
    slow = slow->next;
    fast = fast->next->next;
  }
  ListNode *reverseHead = reverseList(slow->next);
  // 比较
  ListNode *p1 = head;
  ListNode *p2 = reverseHead;
  while (p1 != nullptr && p2 != nullptr){
    if (p1->val != p2->val){
      return false;
    }
    p1 = p1->next;
    p2 = p2->next;
  }
  return true;
}

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