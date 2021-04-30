// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？

// 请你找出所有和为 0 且不重复的三元组。

// 作者：liweiwei1419
// 链接：https://leetcode-cn.com/leetbook/read/learning-algorithms-with-leetcode/x1up56/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> ret;
      int n = nums.size();
      if (n < 3){
        return ret;
      }
      int left = 0, right = 0;
      int target = 0;
      sort(nums.begin(), nums.end());
      for (int i = 0; i != nums.size(); ++i){
        if (nums[i] > 0){
          break;
        }
        if (i > 0 && nums[i] == nums[i - 1]){
          continue;
        }
        left = i + 1;
        right = n - 1;
        target = -nums[i];
        while (left < right){
          if (nums[left] + nums[right] > target){
            --right;
          }else if (nums[left] + nums[right] < target){
            ++left;
          }else{
            ret.push_back({nums[i], nums[left], nums[right]});
            while (left < right && nums[left] == nums[left + 1]){
              ++left;
            }
            while (left < right && nums[right] == nums[right - 1]){
              --right;
            }
            ++left;
            --right;
          }
        }
      }
      return ret;
    }
};