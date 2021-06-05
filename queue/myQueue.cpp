// 请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

// 实现 MyQueue 类：

// void push(int x) 将元素 x 推到队列的末尾
// int pop() 从队列的开头移除并返回元素
// int peek() 返回队列开头的元素
// boolean empty() 如果队列为空，返回 true ；否则，返回 false


// 作者：liweiwei1419
// 链接：https://leetcode-cn.com/leetbook/read/learning-algorithms-with-leetcode/5drja5/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> stkpop, stkpush;

    void moveStk() {
      // 从第一个栈移动到第二个
      while (!stkpush.empty()){
        stkpop.push(stkpush.top());
        stkpush.pop();
      }
    }

    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
      stkpush.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
      if (empty()){
        return -1;
      }
      if (stkpop.empty()){
        moveStk();
      }
      int temp = stkpop.top();
      stkpop.pop();
      return temp;
    }
    
    /** Get the front element. */
    int peek() {
      if (empty()){
        return -1;
      }
      if (stkpop.empty()){
        moveStk();
      }
      return stkpop.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
      if (stkpop.empty() && stkpush.empty()){
        return true;
      }else{
        return false;
      }
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