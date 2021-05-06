// 传送带上的包裹必须在 D 天内从一个港口运送到另一个港口。

// 传送带上的第 i 个包裹的重量为 weights[i]。每一天，我们都会按给出重量的顺序往传送带上装载包裹。我们装载的重量不会超过船的最大运载重量。

// 返回能在 D 天内将传送带上的所有包裹送达的船的最低运载能力

// 作者：liweiwei1419
// 链接：https://leetcode-cn.com/leetbook/read/learning-algorithms-with-leetcode/x4nmbv/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


class Solution {
public:
    bool check(vector<int>& weights, int D, int mid){
      int sum = 0;
      // 统计需要的天数
      int cnt = 1;
      for (int i = 0; i < weights.size(); ++i){
        if ( sum + weights[i] > mid){
          ++cnt;
          sum = weights[i];
        }else {
          sum += weights[i];
        }
      }
      return cnt <= D;
    }
    int shipWithinDays(vector<int>& weights, int D) {
      int left = 0, right = 0;
      for (auto p : weights){
        right += p;
        left = (p > left) ? p : left;
      }
      while (left < right){
        int mid = (left + right) >> 1;
        // 无法在指定的D天内完成任务
        if (!check(weights, D, mid)){
          left = mid + 1;
        }else {
          right = mid;
        }
      }
      return left;
    }
};