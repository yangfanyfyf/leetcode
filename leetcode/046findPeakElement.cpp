// 峰值元素是指其值大于左右相邻值的元素。

// 给你一个输入数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。

// 你可以假设 nums[-1] = nums[n] = -∞ 。

int findPeakElement(vector<int>& nums) {
  if (nums.size() == 1) return 0;
  for (int i = 1; i != nums.size() - 1; ++i){
    if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]){
      return i;
    }
  }
  if (nums[0] > nums[1]) return 0;
  if (nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;
  return -1;
}

int findPeakElement(vector<int>& nums) {
  int left = 0, right = nums.size() - 1;
  while(left < left){
    int mid = left + (right - left) / 2;
    if (nums[mid] < nums[mid + 1]){
      left = mid + 1;
    }else{
      right = mid;
    }
  }
  return left;
}


