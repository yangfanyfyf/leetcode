// 给定一个包含 n + 1 个整数的数组 nums ，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。

// 假设 nums 只有 一个重复的整数 ，找出 这个重复的数 。

//  

// 作者：liweiwei1419
// 链接：https://leetcode-cn.com/leetbook/read/learning-algorithms-with-leetcode/x4r6e2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      int n = nums.size();
      int left = 1, right = n - 1, ans = -1;
      while (left <= right){
        int mid = (left + right) >> 1;
        int cnt = 0;
        // 统计的是 小于等于 mid 的值的个数
        for (int i = 0; i != n; ++i){
          cnt += nums[i] <= mid;
        }
        // 数字的大小不会超过n
        if (cnt <= mid){
          left = mid + 1;
        } else {
          right = mid - 1;
          ans = mid;
        }
      }
      return ans;
    }
};