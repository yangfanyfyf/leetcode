// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

// 注意：给定 n 是一个正整数。

class Solution {
public:
    int climbStairs(int n) {
      if (n < 3){
        return n;
      }
      int s1 = 1, s2 = 2, s3 = 0;
      for (int i = 3; i <= n; ++i){
        s3 = s1 + s2;
        s1 = s2;
        s2 = s3;
      }
      return s3;
    }
};