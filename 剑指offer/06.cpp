// 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。


class Solution {
    vector<int> ret;
public:
    vector<int> reversePrint(ListNode* head) {
        // 递归
        if (head == NULL){
            return {};
        }
        ret = reversePrint(head->next);
        ret.push_back(head->val);
        return ret;
    }
};