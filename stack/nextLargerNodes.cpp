// 给出一个以头节点 head 作为第一个节点的链表。链表中的节点分别编号为：node_1, node_2, node_3, ... 。

// 每个节点都可能有下一个更大值（next larger value）：对于 node_i，如果其 next_larger(node_i) 是 node_j.val，那么就有 j > i 且  node_j.val > node_i.val，而 j 是可能的选项中最小的那个。如果不存在这样的 j，那么下一个更大值为 0 。

// 返回整数答案数组 answer，其中 answer[i] = next_larger(node_{i+1}) 。

// 注意：在下面的示例中，诸如 [2,1,5] 这样的输入（不是输出）是链表的序列化表示，其头节点的值为 2，第二个节点值为 1，第三个节点值为 5 。

// 作者：liweiwei1419
// 链接：https://leetcode-cn.com/leetbook/read/learning-algorithms-with-leetcode/5doen1/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 单调栈
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        if (!head) return {};
        vector<int> temp;
        stack<int> mono_stk;
        ListNode *curr = head;
        while (curr){
            temp.push_back(curr->val);
            curr = curr->next;
        }
        int n = temp.size();
        vector<int> ret(n);
        // 从最右侧开始遍历
        for (int i = n - 1; i >= 0; --i){
            // 找到离i最近的大于他的数字
            while (!mono_stk.empty() && temp[i] >= mono_stk.top()){
                mono_stk.pop();
            }
            if (mono_stk.empty()) {
                ret[i] = 0;
            }else {
                ret[i] = mono_stk.top();
            }
            mono_stk.push(temp[i]);
        }
        return ret;
    }
};