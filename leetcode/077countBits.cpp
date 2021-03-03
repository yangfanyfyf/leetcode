// 给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。




// 计算从0到num的所有数字的1的个数？
int countOnes(int x){
  int ones = 0;
  while (x > 0){
    x &= (x - 1);
    ++ones;
  }
  return ones;
}
vector<int> countBits(int num) {
  vector<int> ret(num + 1, 0);
  for (int i = 0; i <= num; ++i){
    ret[i] = countOnes(i);
  }
  return ret;
}