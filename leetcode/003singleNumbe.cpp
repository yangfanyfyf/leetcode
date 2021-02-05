// 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

// 说明：

// 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

// 先排序再判断？
int singleNumber(vector<int>& nums){
  if (nums.empty()){
    return -1;
  }
  if (nums.size() == 0){
    return nums[0];
  }
  sort(nums.begin(), nums.end());
  for (int i = 1; i != nums.size() - 1; ++i){
    if (nums[i - 1] != nums[i] && nums[i] != nums[i + 1]){
      return nums[i];
    }
    if (nums[i - 1] == nums[i] && nums[i] != nums[i + 1] && i == nums.size() - 2){
      return nums[i + 1];
    }
    if (nums[i - 1] != nums[i] && nums[i] == nums[i + 1] && i == 1){
      return nums[i - 1];
    }
  }
  return -1;
}


// 使用位运算
int singleNumber(vector<int>& nums){
  int ret = 0;
  for (auto p : nums) ret ^= p;
  return ret;
}
