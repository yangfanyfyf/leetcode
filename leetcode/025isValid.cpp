// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

// 将左括号压入，遇到右括号则弹出
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// bool isValid(string s){
//   if (s.size() == 0){
//     return true;
//   }
//   stack<char> myStack;
//   // 遍历字符串
//   for (auto ch : s){
//     if (myStack.size() == 0 && (ch == ')' || ch == ']' || ch == '}')){
//       return false;
//     }

//     if (ch == '(' || ch == '[' || ch == '{'){
//       myStack.push(ch);
//     }else if(ch == ')' && myStack.top() == '(' || ch == ']' && myStack.top() == '[' || ch == '}' && myStack.top() == '{'){
//       myStack.pop();
//     }else{
//       // cout << myStack.top() << endl;
//       cout << "#1" << endl;
//       return false;
//     }
//   }
//   if (myStack.size() != 0){
//     cout << "#2" << endl;
//     return false;
//   }else{
//     return true;
//   }
// }

bool isValid(string s){
  if (s.empty()){
    return true;
  }
  stack<char> myStack;
  for (auto ch : s){
    if (myStack.empty()){
      myStack.push(ch);
    }else if (ch == ')' && myStack.top() == '(' || ch == ']' && myStack.top() == '[' || ch == '}' && myStack.top() == '{'){
      myStack.pop();
    }else{
      myStack.push(ch);
    }
  }
  return myStack.empty();
}





int main(){
  string s = "(){}[]";
  cout << isValid(s) << endl;
}