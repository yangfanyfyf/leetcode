// 使用数组实现循环队列

// 不需要定义头尾，只需要头部和已有长度

class MyCircularQueue {
public:
    vector<int> myQueue;
    int frontIndex;
    int count;
    int Capacity;

    // 设置队列长度
    MyCircularQueue(int k) {
      myQueue = vector<int> (k);
      count = 0;
      frontIndex = 0;
      Capacity = k;
    }
    
    bool enQueue(int value) {
      if (count == Capacity) return false;
      myQueue[(frontIndex + count) % Capacity] = value;
      ++count;
      return true;
    }
    
    // 出列是从头部
    bool deQueue() {
      if (count == 0) return false;
      frontIndex = (frontIndex + 1) % Capacity;
      --count;
      return true;
    }
    
    int Front() {
      if (count == 0) return -1;
      return myQueue[frontIndex];
    }
    
    int Rear() {
      if (count == 0) return -1;
      int endIndex = (frontIndex + count - 1) % Capacity;
      return myQueue[endIndex];
    }
    
    bool isEmpty() {
      return count == 0;
    }
    
    bool isFull() {
      return count == Capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */