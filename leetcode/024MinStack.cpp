//  实现最小栈


class MinStack {
    stack<int> _myStack;
    stack<int> _minStack;
public:
    /** initialize your data structure here. */
    MinStack() {
        _minStack.push(INT_MAX);
    }
    
    void push(int x) {
      _myStack.push(x);
      _minStack.push(min(_minStack.top(), x));
    }
    
    void pop() {
      _myStack.pop();
      _minStack.pop();
    }
    
    int top() {
      return _myStack.top();
    }
    
    int getMin() {
      return _minStack.top();
    }
};



// 只使用一个stack
class MinStack{
private:
  stack<pair<int, int> > _myStack;
public:
  MinStack(){

  }
  void push(int x){
    if (_myStack.size() == 0){
      _myStack.push({x, x});
    }else{
      _myStack.push({x, min(_myStack.top().second, x)});
    }
  }

  void pop(){
    _myStack.pop();
  }

  int top(){
    return _myStack.top().first;
  }

  int getMin(){
    return _myStack.top().second;
  }


};