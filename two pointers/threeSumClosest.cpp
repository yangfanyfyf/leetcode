// 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。

// 返回这三个数的和。假定每组输入只存在唯一答案。

// 作者：liweiwei1419
// 链接：https://leetcode-cn.com/leetbook/read/learning-algorithms-with-leetcode/x1tex2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

#include <vector>
using std::vector;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      int n = nums.size();
      int temp = 1e6, left = 0, right = 0;
      sort(nums.begin(), nums.end());
      for (int i = 0; i != n; ++i){
        if (i > 0 && nums[i] == nums[i - 1]){
          continue;
        }

        left = i + 1;
        right = n - 1;

        while (left < right){
          int sum = nums[i] + nums[left] + nums[right];
          if (sum == target){
            return target;
          }
          if (abs(sum - target) < abs(temp - target)){
            temp = sum;
          }
          if (sum > target){
            --right;
            while (left < right && nums[right] == nums[right + 1]){
              --right;
            }
          }else if (sum <=target){
            ++left;
            while (left < right && nums[left] == nums[left - 1]){
              ++left;
            }
          }
        }
      }
      return temp;
    }
};