// 给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。

// 它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

// 你可以假设除了数字 0 之外，这两个数字都不会以零开头。



// 作者：liweiwei1419
// 链接：https://leetcode-cn.com/leetbook/read/learning-algorithms-with-leetcode/5ej8am/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// 先将两个链表翻转，相加后再翻转？
// 特殊条件过多
// 无法枚举

// class Solution {
// public:
//     ListNode *reverse(ListNode *head){
//       ListNode *prev = nullptr;
//       ListNode *curr = head;
//       while (curr){
//         // 保存
//         ListNode *next = curr->next;
//         // 重新指向
//         curr->next = prev;
//         // 向后移一位
//         prev = curr;
//         curr = next;
//       }
//       return prev;
//     }
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      
//       ListNode *rL1 = reverse(l1);
//       ListNode *rL2 = reverse(l2);
//       ListNode *dummyHead = rL1;
//       int flag = 0;
//       while (rL1->next != nullptr && rL2->next != nullptr){
//         if (rL1->val + rL2->val + flag > 9){
//           rL1->val = (rL1->val + rL2->val + flag) % 10;
//           flag = 1;
//         }else {
//           rL1->val = (rL1->val + rL2->val + flag) % 10;
//           flag = 0;
//         }
//         rL1 = rL1->next;
//         rL2 = rL2->next;
//       }
//         if (rL1->val + rL2->val + flag > 9){
//           rL1->val = (rL1->val + rL2->val + flag) % 10;
//           flag = 1;
//         }else {
//           rL1->val = (rL1->val + rL2->val + flag) % 10;
//           flag = 0;
//         }
      
//       if (rL1->next == nullptr){
//         rL1->next = rL2->next;
//         rL1->next->val += flag;
//       }
//       if (rL2->next == nullptr){
//         rL1->next->val += flag;
//       }
//       return reverse(dummyHead);
//     }
// };

// 逆序处理，应该使用栈

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      stack<int> s1, s2;
      while (l1){
        s1.push(l1->val);
        l1 = l1->next;
      }
      while (l2){
        s2.push(l2->val);
        l2 = l2->next;
      }

      int carry = 0;
      ListNode *ans = nullptr;
      // 处理累加数的方法，之前想得太复杂了
      while (!s1.empty() || !s2.empty() || carry != 0){
        int a = s1.empty() ? 0 : s1.top();
        int b = s2.empty() ? 0 : s2.top();
        if (!s1.empty()) s1.pop();
        if (!s2.empty()) s2.pop();
        int cur = a + b + carry;
        carry = cur / 10;
        cur %= 10;
        auto curNode = new ListNode(cur);
        curNode->next = ans;
        ans = curNode;
      }
      return ans;
    }
};