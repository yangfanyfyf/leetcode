// 假设按照升序排序的数组在预先未知的某个点上进行了旋转。例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] 。

// 请找出其中最小的元素。

// 遍历
int findMin(vector<int>& nums) {
  if (nums.size() == 1){
    return nums[0];
  }
  for (int i = 0; i != nums.size() - 1; ++i){
    if (nums[i] > nums[i + 1]){
      return nums[i + 1];
    }
  }
  return nums[0];
}

// 二分法
int findMin(vector<int>& nums) {
  int left = 0, right = nums.size() - 1;
  while (left < right){
    int mid = left + (right - left) / 2;
    // 最左侧的值一定是大于最右侧的值的
    if (nums[left] <= nums[mid]){
      if (nums[mid] > nums[right]){
        left = mid + 1;
      }else{
        return nums[left];
      }
    }else{
      right = mid;
    }
  }
  return nums[left];
}