// 给你一个整数数组 arr 和一个目标值 target ，请你返回一个整数 value ，

// 使得将数组中所有大于 value 的值变成 value 后，数组的和最接近  target （最接近表示两者之差的绝对值最小）。

// 如果有多种使得和最接近 target 的方案，请你返回这些整数中的最小值。

// 请注意，答案不一定是 arr 中的数字。

// 作者：liweiwei1419
// 链接：https://leetcode-cn.com/leetbook/read/learning-algorithms-with-leetcode/x4p85c/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
      sort (arr.begin(), arr.end());
      int n = arr.size();
      vector<int> prefix(n + 1);
      // 对排序后的数组进行累加
      for (int i = 1; i <= n; ++i){
        prefix[i] = prefix[i - 1] + arr[i - 1];
      }
      // 找到最大的元素
      int r = *max_element(arr.begin(), arr.end());
      int ans = 0;
      int diff = target;
      // 枚举
      for (int i = 1; i <= r; ++i){
        // 二分查找，也即是大于等于i出现的第一个位置，
        // 另外还有upper_bound, binary_bound;
        auto iter = lower_bound(arr.begin(), arr.end(), i);
        int cur = prefix[iter - arr.begin()] + (arr.end() - iter) * i;
        if (abs(cur - target) < diff){
          ans = i;
          diff = abs(cur - target);
        }
      }
      return ans;
    }
};