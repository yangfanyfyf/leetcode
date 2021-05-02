// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，

// 写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

// 作者：liweiwei1419
// 链接：https://leetcode-cn.com/leetbook/read/learning-algorithms-with-leetcode/xsshgi/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
      int n = nums.size();
      if (n == 0){
        return -1;
      }
      int left = 0;
      int right = n - 1;
      int mid = 0;
      while (left <= right){
        mid = left + (right - left) / 2;
        if (nums[mid] == target){
          return mid;
        }else if (nums[mid] > target){
          right = mid - 1;
        }else{
          left = mid + 1;
        }
      }
      return -1;
    }
};