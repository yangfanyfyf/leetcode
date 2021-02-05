// 给定一个整数数组，判断是否存在重复元素。

// 如果存在一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。

// 可以完全遍历一遍
// 超时了！
bool containsDuplicate(vector<int>& nums) {
  bool ret = false;
  for (auto it = nums.begin(); it != nums.end(); ++it ){
    if (std::find(nums.begin(), nums.end(), *it) != nums.end() ){
      if (std::find(nums.begin(), nums.end(), *it) == it) continue;
        ret = true;
      }
  }
}


bool containsDuplicate(vector<int>& nums) {
  if (nums.empty()){
    return false;
  }
  sort(nums.begin(), num.end());
  for (int i = 0; i != nums.size() - 1; ++i){
    if (nums[i] == nums[i + 1]){
      return true;
    }
  }
  return false;
}