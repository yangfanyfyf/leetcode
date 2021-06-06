// 用队列实现栈

// 请你仅使用两个队列实现一个后入先出（LIFO）的栈，

// 并支持普通队列的全部四种操作（push、top、pop 和 empty）。

// 两个栈交替压入
class MyStack {
public:
    queue<int> queue1, queue2;
    /** Initialize your data structure here. */
    void moveQueue(queue<int>& inQueue, queue<int>& outQueue){
        while(!outQueue.empty()){
            inQueue.push(outQueue.front());
            outQueue.pop();
        }
    }

    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if (queue1.empty() && queue2.empty()){
            queue1.push(x);
        }else if (queue1.empty() && !queue2.empty()){
            queue1.push(x);
            moveQueue(queue1, queue2);
        }else if (!queue1.empty() && queue2.empty()){
            queue2.push(x);
            moveQueue(queue2, queue1);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp;
        if (queue1.empty()){
            temp = queue2.front();
            queue2.pop();
        }else {
            temp = queue1.front();
            queue1.pop();
        }
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        if (queue1.empty()){
            return queue2.front();
        }else {
            return queue1.front();
        }
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if (queue1.empty() && queue2.empty()){
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */