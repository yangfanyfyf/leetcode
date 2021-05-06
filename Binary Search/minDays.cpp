// 给你一个整数数组 bloomDay，以及两个整数 m 和 k 。

// 现需要制作 m 束花。制作花束时，需要使用花园中 相邻的 k 朵花 。

// 花园中有 n 朵花，第 i 朵花会在 bloomDay[i] 时盛开，恰好 可以用于 一束 花中。

// 请你返回从花园中摘 m 束花需要等待的最少的天数。如果不能摘到 m 束花则返回 -1 。

// 作者：liweiwei1419
// 链接：https://leetcode-cn.com/leetbook/read/learning-algorithms-with-leetcode/x4voyj/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    int check(vector<int>& bloomDay, int m, int k, int mid){
      int start = 0;
      for (int i = 0; i != bloomDay.size(); ++i){
        // 满足开花时间
        if (bloomDay[i] <= mid){
          // 可以组成一束花，重新计数
          if (++start == k){
            --m;
            if (m == 0){
              return true;
            }
            start = 0;
          }
        }else{
          // 不连续，重新计数
          start = 0;
        }
      }
      return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
      long long left = 0, right = 1e9;
      if (m * k > bloomDay.size()){
        return -1;
      }
      while (left < right){
        long long mid = left + (right - left) / 2;
        if (!check(bloomDay, m, k, mid)){
          left = mid + 1;
        }else {
          right = mid;
        }
      }
      return left;
    }
};