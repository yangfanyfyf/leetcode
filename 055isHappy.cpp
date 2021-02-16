// 编写一个算法来判断一个数 n 是不是快乐数。

// 首先，将数字的各个位分开
// 然后，经数字加入到hashset中，如果出现了重复值，那么说明不是快乐数
int newNum(int n){
  int total = 0;
  while (n > 0){
    int d = n % 10;
    n = n / 10;
    total += d * d;
  }
  return total;
}

bool isHappy(int n){
  unordered_set<int> hashset;
  while (n != 1 && hashset.count(n) <= 0){
    hashset.insert(n);
    n = newNum(n);
  }
  return n == 1;
}