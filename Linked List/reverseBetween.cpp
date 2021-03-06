// 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。

// 请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
//  

// 作者：liweiwei1419
// 链接：https://leetcode-cn.com/leetbook/read/learning-algorithms-with-leetcode/5e36z2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


// class Solution {
// public:
//     ListNode* reverseBetween(ListNode* head, int left, int right) {
//       ListNode* start = nullptr, *end = nullptr, *curr = head;
//       int k = 1;
//       // 找到指定的节点
//       while (curr){
//         curr = curr->next;
//         ++k;
//         if (k == left - 1){
//           start = curr;
//         }
//         if (k == right){
//           end = curr;
//           break;
//         }
//       }

//       ListNode* oldStart = start->next;
//       ListNode* oldEnd = end->next;
//       ListNode* prev = nullptr;
//       ListNode* curr = start->next;
//       while (curr != end->next){
//         ListNode* temp = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = temp;
//       }

//       oldStart->next = oldEnd;
//       start->next = prev;

//       return head;
      
      
//     }
// };



class Solution {
public:
    void reverseLinkedList(ListNode *head){
      ListNode *pre = nullptr;
      ListNode *cur = head;
      while (cur != nullptr){
        ListNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
      }
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      // 找到两个节点的位置
      ListNode *dummyNode = new ListNode(-1);
      dummyNode->next = head;

      ListNode *pre = dummyNode;
      for (int i = 0; i != left - 1; ++i){
        pre = pre->next;
      }

      ListNode *rightNode = pre;
      for (int i = 0; i != right - left + 1; ++i){
        rightNode = rightNode->next;
      }
      ListNode *leftNode = pre->next;
      ListNode *curr = rightNode->next;

      pre->next = nullptr;
      rightNode->next = nullptr;

      reverseLinkedList(leftNode);

      pre->next = rightNode;
      leftNode->next = curr;
      return dummyNode->next;
    }
};
