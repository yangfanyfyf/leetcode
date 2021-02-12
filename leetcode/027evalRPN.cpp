// 根据 逆波兰表示法，求表达式的值。

// 有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

int evalRPN(vector<string>& tokens) {
  stack<int> s;
  int tempNum = 0;
  for (size_t i = 0; i != tokens.size(); ++i){
    if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
      s.push(stoi(tokens[i]));
      continue;
    }
    // 判断运算符号
    if (tokens[i] == "+"){
      int first = s.top();
      s.pop();
      int second = s.top();
      s.pop();
      s.push(second + first);
    }
    if (tokens[i] == "-"){
      int first = s.top();
      s.pop();
      int second = s.top();
      s.pop();
      s.push(second - first);
    }
    if (tokens[i] == "*"){
      int first = s.top();
      s.pop();
      int second = s.top();
      s.pop();
      s.push(second * first);
    }
    if (tokens[i] == "/"){
      int first = s.top();
      s.pop();
      int second = s.top();
      s.pop();
      s.push(second / first);
    }

  }
  return s.top();
}

int main(){
  vector<string> num = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
  int i = evalRPN(num);
  cout << i << endl;
}
