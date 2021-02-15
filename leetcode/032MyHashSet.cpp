
class MyHashSet {
public:
    vector<ListNode*> ms;
    // 1e4的存储区域
    int n = 1e4;
    /** Initialize your data structure here. */
    MyHashSet() {
        ms = vector<ListNode*> (n);
    }
    // 添加元素
    void add(int key) {
        int idx = key % n;
        // 当桶为空时，新建一个节点，用于存储key
        if (ms[idx] == nullptr)
            ms[idx] = new ListNode(key);
        else{
            // 计算得到的桶非空，那么就建立一个指向这个桶的指针
            ListNode* node = ms[idx];
            // 键值已经存在，跳出
            if (node->val == key)
                return;
            // 开始遍历整个链表
            while (node->next != nullptr){
                if (node->next->val == key)
                    return;
                node = node->next;
            }
            // 键值不在桶中，插入新的节点
            node->next = new ListNode(key);
        }
    }
    // 移除元素
    void remove(int key) {
        int idx = key % n;
        // 桶为空，无法删除
        if (ms[idx] == nullptr){
            return;
        }
        if (ms[idx]->val == key){
            // 不删除？直接跳过了一个节点？
            ms[idx] = ms[idx]->next;
        }else{
            ListNode *pre = ms[idx];
            ListNode *node = pre->next;
            while (node != nullptr){
                if (node->val == key){
                    // 找到该节点，直接跳过
                    pre->next = node->next;
                    return;
                }
                pre = node;
                node = node->next;
            }
        }
    }
    // 是否包含元素
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int idx = key % n;
        ListNode *node = ms[idx];
        while (node != nullptr){
            if (node->val == key){
                return true;
            }
            node = node->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */