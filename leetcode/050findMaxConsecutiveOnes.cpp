// 给定一个二进制数组， 计算其中最大连续1的个数。


int findMaxConsecutiveOnes(vector<int>& nums) {
  vector<int> ret(nums.size(), 0);
  int k = 0;
  for (int i = 0; i != nums.size(); ++i){
    if (nums[i] == 1){
      ++ret[k];
    }
    if (nums[i] != 1){
      ++k;
    }
  }
  int maxK = 0;
  for (auto x : ret){
    if (x >= maxK)
      maxK = x;
  }
  return maxK;
}

// 最大值可以只使用一个值实现