// 珂珂喜欢吃香蕉。这里有 N 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 H 小时后回来。

// 珂珂可以决定她吃香蕉的速度 K （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 K 根。

// 如果这堆香蕉少于 K 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。  

// 珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。

// 返回她可以在 H 小时内吃掉所有香蕉的最小速度 K（K 为整数）。

// 作者：liweiwei1419
// 链接：https://leetcode-cn.com/leetbook/read/learning-algorithms-with-leetcode/x4a0he/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


class Solution {
public:
    bool possible(vector<int> &piles, int h, int k){
      int time = 0;
      for (auto p : piles){
        // 向上取整
        time += (p - 1) / k + 1;
      }
      return time <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
      int lo = 1, hi = pow(10, 9);
      while (lo < hi){
        int mi = lo + (hi - lo) / 2;
        if (!possible(piles, h, mi)){
          lo = mi + 1;
        }else {
          hi = mi;
        }
      }
      // 返回的是最小速度
      return lo;
    }
};