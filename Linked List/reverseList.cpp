// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。


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
// 迭代，
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      ListNode* prev = nullptr;
      ListNode* curr = head;
      while(curr){
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
      }
      return prev;
    }
};

// 递归

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      if (!head || !head->next){
        return head;
      }
      ListNode* newNode = reverseList(head->next);
      head->next->next = head;
      head->next = nullptr;
      return newNode;
    }
};