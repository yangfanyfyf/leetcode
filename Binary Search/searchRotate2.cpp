// 已知存在一个按非降序排列的整数数组 nums ，数组中的值不必互不相同。

// 给你 旋转后 的数组 nums 和一个整数 target ，请你编写一个函数来判断给定的目标值是否存在于数组中。

// 如果 nums 中存在这个目标值 target ，则返回 true ，否则返回 false 。

// 作者：liweiwei1419
// 链接：https://leetcode-cn.com/leetbook/read/learning-algorithms-with-leetcode/x4hadh/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 其他和上一个程序相同

#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
      int n = nums.size();
      if (n == 0) return false;
      if (n == 1) return nums[0] == target;
      int left = 0, right = n - 1, mid = 0;
      while (left <= right){
        mid = left + (right - left) / 2;
        if (nums[mid] == target){
          return true;
        }
        if (nums[left] == nums[mid] && nums[mid] == nums[right]){
          ++left;
          --right;
        }else if (nums[mid] >= nums[left]){
          if (nums[mid] > target && target >= nums[left]){
            right = mid - 1;
          }else{
            left = mid + 1;
          }
        }else if (nums[mid] < nums[left]){
          if (nums[mid] < target && target <= nums[right]){
            left = mid + 1;
          }else{
            right = mid - 1;
          }
        }
      }
      return false;
    }
};