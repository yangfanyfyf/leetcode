// 设计一个哈希映射

class MyHashMap {
// 单独建立一个节点
struct Node
{
  int mkey;
  int mval;
  Node *next;
  Node(int key, int val) : mkey(key), mval(val), next(nullptr){}
};
int len = 10000;
public:
    vector<Node*> arr;
    /** Initialize your data structure here. */
    MyHashMap() {
      arr = vector<Node*> (len, new Node(-1, -1));
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
      int temp = key % len; // 函数
      // 当前节点
      Node *curr = arr[temp];
      // 之前的节点
      Node *prev;
      // 对桶进行搜索，如果桶是空的，也会进入一次循环
      // curr 会指向nullptr, prev会指向桶的第一个元素
      // 不是空的，那么curr会指向指定过的key位置，并重新赋值
      while (curr){
        if (curr->mkey == key){
          curr->mval = value;
          return;
        }
        prev = curr;
        curr = curr->next;
      }
      // 当curr未搜索到时，直接插入新的节点
      Node *node = new Node(key, value);
      prev->next = node;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
      int temp = key % len;
      Node *curr = arr[temp];
      while(curr){
        if (curr->mkey == key){
          // 返回key对应的value
          return curr->mval;
        }
        curr = curr->next;
      }
      return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
      int temp = key % len;
      Node *curr = arr[temp];
      Node *prev;
      while (curr){
        if (curr->mkey == key){
          prev->next = curr->next;
          return;
        }
        prev = curr;
        curr = curr->next;
      }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */