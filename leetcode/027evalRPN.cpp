// 根据 逆波兰表示法，求表达式的值。

// 有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int evalRPN(vector<string>& tokens) {
  stack<int> s;
  int tempNum = 0;
  for (size_t i = 0; i != tokens.size(); ++i){
    if (tokens[i] != '+' && tokens[i] != '-' && tokens[i] != '*' && tokens[i] != '/'){
      s.push((int)tokens[i]);
      continue;
    }
    // 判断运算符号
    switch(tokens[i]){
      case '+':
        tempNum = tokens[i-1] + tokens[i-2];
        break;
      case '-':
        tempNum = tokens[i-1] - tokens[i-2];
        break;
      case '*':
        tempNum = tokens[i-1] * tokens[i-2];
        break;
      case '/':
        tempNum = tokens[i-1] / tokens[i-2];
        break;
      default:
        break;
    }
    
  }
}