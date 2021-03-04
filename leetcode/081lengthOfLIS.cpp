// 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。



int lengthOfLIS(vector<int>& nums) {
  int n = nums.size();
  if (n == 0){
    return 0;
  }
  vector<int> dp(n, 0);
  for (int i = 0; i != n; ++i){
    dp[i] = 1;
    for (int j = 0; j < i; ++j){
      // 如果出现了递增，那么加1
      if (nums[j] < nums[i]){
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  return *max_element(dp.begin(), dp.end());
}