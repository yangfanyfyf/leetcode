// 给定一个链表，判断链表中是否有环
// 使用快慢指针
// 慢指针每次移动1步，快指针每次移动两步

bool hasCycle(ListNode *head){
  if (head == nullptr || head->next == nullptr){
    return false;
  }
  hasCycle *slow = head;
  hasCycle *fast = head->next;
  // 如何知道快指针再次超过了慢指针？
  // 当两者相等时跳出循环
  // 或者快指针为空
  while (slow != fast){
    if (fast == nullptr || fast->next == nullptr){
      return false;
    }
    slow = slow->next;
    fast = fast->next->next;
  }
  return true;
}