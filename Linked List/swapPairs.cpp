// 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || head->next == nullptr){
            return head;
        }
      ListNode *dummyNode = new ListNode(-1);
      dummyNode->next = head;

      ListNode *fir = dummyNode;
      ListNode *sec = head;
      ListNode *thr = head->next;
      ListNode *fou = thr->next;
      
      while (thr){
        fir->next = thr;
        thr->next = sec;
        sec->next = fou;
        
        fir = sec;
        if (!fir){
          break;
        }
        sec = fir->next;
        if (!sec){
          break;
        }
        thr = sec->next;
        if (!thr){
          break;
        }
        fou = thr->next;
        
      }
      return dummyNode->next;
    }
};


// 递归
// 真简洁啊
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
      if (head == nullptr || head->next == nullptr)[
        return head;
      ]
      ListNode *newHead = head->next;
      head->next = swapPairs(newHead->next);
      newHead->next = head;
      return newHead;
    }
};