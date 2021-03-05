// 请你仅使用两个栈实现先入先出队列。

// 队列应当支持一般队列的支持的所有操作（push、pop、peek、empty）


class MyQueue {
private:
    stack<int> inStack, outStack;
    void in2out(){
      while (!inStack.empty()){
        outStack.push(inStack.top());
        inStack.pop();
      }
    }
public:
    /** Initialize your data structure here. */
    MyQueue() {
      
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
      inStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
      if (outStack.empty()){
        in2out();
      }
      int x = outStack.top();
      outStack.pop();
      return x;
    }
    
    /** Get the front element. */
    int peek() {
      if (outStack.empty()){
        in2out();
      }
      return outStack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
      return inStack.empty() && outStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */