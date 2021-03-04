// 在整数数组 nums 中，是否存在两个下标 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值小于等于 t ，且满足 i 和 j 的差的绝对值也小于等于 ķ 。

// 如果存在则返回 true，不存在返回 false。

// 遍历数组，n^2时间复杂度

// 无法通过，abs会溢出
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
  if (nums.size() < 2){
    return false;
  }
  for (int i = 0; i != nums.size(); ++i){
    for (int j = i + 1; j != nums.size(); ++j){
      if (abs(nums[i] - nums[j]) <= t && abs(i - j) <= k){
        return true;
      }
    }
  }
  return false;
}

// C++中二叉树是使用set实现的
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
  set<long> s;
  for (int i = 0; i != nums.size(); ++i){
    auto pos = s.lower_bound(long(nums[i]) - t);
    if (pos != s.end() && *pos <= long(nums[i]) + t)
      return true;
    // 将数组元素插入到set中
    s.insert(nums[i]);
    // 只维持一定长度的set
    if (s.size() > k){
      s.erase(nums[i-k]);
    }
  }
  return false;
}