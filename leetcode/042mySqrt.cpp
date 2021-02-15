// 实现 int sqrt(int x) 函数。

// 计算并返回 x 的平方根，其中 x 是非负整数。

// 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
#include <iostream>
using namespace std;

int mySqrt(int x) {
  int L = 0;
  int R = x;
  while (L <= R)
  {
    int mid = L + (R - L) / 2;
    cout << "mid = " << mid << endl;
    if ((long long)mid * mid == x){
      return mid;
    }else if ((long long)mid * mid < x){
      L = mid + 1;
    }else{
      R = mid - 1;
    }
  }
  // 最后找到的mid == L
  return L - 1;
}

int main(){
  int x = 2147395599;
  int ret = mySqrt(x);
  cout << ret << endl;
}