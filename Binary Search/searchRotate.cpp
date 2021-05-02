// 整数数组 nums 按升序排列，数组中的值 互不相同 。

// 在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，

// 使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。

// 例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

// 给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。

// 作者：liweiwei1419
// 链接：https://leetcode-cn.com/leetbook/read/learning-algorithms-with-leetcode/xsfv0d/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
      int n = nums.size();
      int left = 0, right = n - 1, mid = 0;
      while (left < right){
        mid = left + (right - left) / 2;
        if (nums[mid] == target){
          return mid;
        }else if (nums[mid] >= nums[left]){
          if (nums[mid] > target && nums[left] <= target){
            right = mid;
          }else{
            left = mid + 1;
          }
        }else if (nums[mid] < nums[left]){
          if (nums[mid] < target && nums[right] >= target){
            left = mid + 1;
          }else{
            right = mid;
          }
        }
      }
      if (nums[left] == target){
        return left;
      }
      return -1;
    }
};