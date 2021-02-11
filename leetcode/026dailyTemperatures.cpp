// 请根据每日 气温 列表，重新生成一个列表。对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0 来代替。

// 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> dailyTemperatures(vector<int>& T) {
  // 用于存储返回值
  vector<int> ret(T.size(), 0);
  // 将温度的序号压入
  stack<int> myStack;
  for (int i = 0; i != T.size(); ++i){
    // 当出现较高的温度时，则出栈
    while(!myStack.empty() && T[i] > T[myStack.top()]){
      int prev = myStack.top();
      ret[prev] = i - prev;
      myStack.pop();
    }
    myStack.push(i);
  }
  return ret;
}