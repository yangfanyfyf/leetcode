// 给你两个链表 list1 和 list2 ，它们包含的元素分别为 n 个和 m 个。

// 请你将 list1 中第 a 个节点到第 b 个节点删除，并将list2 接在被删除节点的位置。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/merge-in-between-linked-lists
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        while (curr2->next != nullptr){
          curr2 = curr2->next;
        }
        for (int i = 1; i <= b; ++i){
          curr1 = curr1->next;
        }
        curr2->next = curr1->next;
        curr1->next = nullptr;
        
        curr1 = list1;
        for (int i = 1; i != a; ++i){
          curr1 = curr1->next;
        }
        curr1->next = list2;
        return list1;
    }
};
