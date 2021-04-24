// 给定一个含有 n 个正整数的数组和一个正整数 target 。

// 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，

// 并返回其长度。如果不存在符合条件的子数组，返回 0 。

//  

// 作者：liweiwei1419
// 链接：https://leetcode-cn.com/leetbook/read/learning-algorithms-with-leetcode/x1d3a3/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int len = INT_MAX, sum = 0;
      int l = 0, r = 0;
      while (r < nums.size()){
        sum += nums[r];
        while (sum >= target){
          len = min(len, r - l + 1);
          sum -= nums[l++];
        }
        ++r;
      }
      return len == INT_MAX ? 0 : len;
    }
};