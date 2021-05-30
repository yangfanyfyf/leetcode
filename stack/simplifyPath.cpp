// 给你一个字符串 path ，表示指向某一文件或目录的 Unix 风格 绝对路径 （以 '/' 开头），请你将其转化为更加简洁的规范路径。

class Solution {
public:
    string simplifyPath(string path) {
      // 流
      stringstream is(path);
      stack<string> myStk;
      string res = "", tmp = "";
      while (getline(is, tmp, '/')){
        // 为空或者是一个点，跳过
        if (tmp == "" || tmp == "."){
          continue;
          // 两个点，返回上一层目录，也就是弹出
        }else if (tmp == ".." && !myStk.empty()){
          myStk.pop();
          // 其他情况都可以压入
        }else if (tmp != ".."){
          myStk.push(tmp);
        }
      }
      // 重建返回的那个字符串
      while (!myStk.empty()){
        res = '/' + myStk.top() + res;
        myStk.pop();
      }
      if (res.empty()){
        return "/";
      }
      return res;
    }
};