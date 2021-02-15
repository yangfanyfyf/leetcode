// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。

vector<int> twoSum(vector<int>& nums, int target){
  vector<int> ret;
  for (int i = 0; i != nums.size() - 1; ++i){
    // 会跳过负数
    // if (nums[i] >= target) continue;
    for (int j = i + 1; j != nums.size(); ++j){
      // if (nums[j] >= target) continue;
      if (nums[i] + nums[j] == target){
        ret.push_back(nums[i]);
        ret.push_back(nums[j]);
      }
    }
  }
  return ret;
}