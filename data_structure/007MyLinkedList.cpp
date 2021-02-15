// 使用了一个虚拟的头结点

class MyLinkedList {
    struct LinkedNode{
      int val;
      LinkedNode *next;
      LinkedNode(int x) : val(x), next(nullptr){}
    };

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
      _dummyHead = new LinkedNode(0);
      _size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
      if (index < 0 || index > _size-1){
        return -1;
      }
      LinkedNode *curNode = _dummyHead->next;
      // 为什么不能使用--index？
      while (index--){
        curNode = curNode->next;
      }
      return curNode->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
      // 新建指向某个节点的指针
      LinkedNode* newNode = new LinkedNode(val);
      newNode->next = _dummyHead->next;
      _dummyHead->next = newNode;
      ++_size;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
      LinkedNode *newNode = new LinkedNode(val);
      LinkedNode *cur = _dummyHead;
      while(cur->next != nullptr){
        cur = cur->next;
      }
      cur->next = newNode;
      ++_size;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
      if (index > _size || index < 0){
        return;
      }
      LinkedNode *newNode = new LinkedNode(val);
      LinkedNode *cur = _dummyHead;
      while (index--){
        cur = cur->next;
      }
      newNode->next = cur->next;
      cur->next = newNode;
      ++_size;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    // 下标从0开始，所以可以一直循环到index
    void deleteAtIndex(int index) {
      if (index >= _size || index < 0){
        return;
      }
      LinkedNode *cur = _dummyHead;
      while (index--){
        cur = cur->next;
      }

      // 需要用一个单独的指针用于保存要删除的这个节点
      LinkedNode *tempNode = cur->next;
      cur->next = cur->next->next;
      delete tempNode;
      --_size;
    }

private:
    int _size;
    LinkedNode *_dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */