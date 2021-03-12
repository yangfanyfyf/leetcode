// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/3sum
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      int n = nums.size();
      sort(nums.begin(), nums.end());
      vector<vector<int>> ans;

      for (int first = 0; first != n; ++first){
        if (first > 0 && nums[first] == nums[first - 1]){
          continue;
        }
        int third = n - 1;
        int target = - nums[first];
        for (int second = first + 1; second < n; ++second){
          if (second > first + 1 && nums[second] == nums[second - 1]){
            continue;
          }
          while (second < third && nums[second] + nums[third] > target){
            --third;
          }
          if (second == third){
            break;
          }
          if (nums[second] + nums[third] == target){
            ans.push_back({nums[first], nums[second], nums[third]});
          }
        }
      }
      return ans;
    }
};