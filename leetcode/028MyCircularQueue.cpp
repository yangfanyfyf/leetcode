class MyCircularQueue {
private:
    vector<int> data;
    int head;
    int tail;
    int size;
public:
    MyCircularQueue(int k) {
        data.resize(k); // 设置容器的大小
        head = -1;
        tail = -1;
        size = k;
    }
    // 入队
    bool enQueue(int value) {
        if (isFull()){
            return false;
        }
        if (isEmpty()){
            head = 0;
        }
        tail = (tail + 1) % size;
        data[tail] = value;
        return true;
    }
    
    bool deQueue() {
        // 初始状态为空
        if (isEmpty()){
            return false;
        }
        // 同样时空队列，但是头指针不是指向-1
        if (head == tail){
            head = -1;
            tail = -1;
            return true;
        }
        // 移动头指针
        head = (head + 1) % size;
        return true;
    }
    
    int Front() {
        if (isEmpty()){
            return -1;
        }
        return data[head];
    }
    
    int Rear() {
        if (isEmpty()){
            return -1;
        }
        return data[tail];
    }
    
    bool isEmpty() {
        return head == -1;
    }
    
    bool isFull() {
        return ((tail + 1) % size) == head;
    }
};