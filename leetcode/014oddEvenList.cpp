// 给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。
// 请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。


// 定义两个指针，分布指向odd和even

ListNode* oddEvenList(ListNode* head) {
  if (head == nullptr || head->next == nullptr || head->next->next == nullptr){
    return head;
  }
  ListNode *oddPtr = head;
  ListNode *evenPtr = head->next;

  while (oddPtr != nullptr && evenPtr != nullptr ){
    if (evenPtr->next == nullptr){
      return head;
    }

    ListNode *oddTail = oddPtr->next;
    oddPtr->next = evenPtr->next;
    evenPtr->next = evenPtr->next->next;

    oddPtr->next->next = oddTail;

    oddPtr = oddPtr->next;
    evenPtr = evenPtr->next;
  }
  // 需要建立哨兵吗？
  return head;
}