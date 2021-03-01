// 假设按照升序排序的数组在预先未知的某个点上进行了旋转。例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] 。

// 请找出其中最小的元素。

// 使用二分法

// mid 的值与两侧的值比较，判断处在哪一个排序中
int findMin(vector<int>& nums) {
  if (nums.size() == 1){
    return nums[0];
  }
  int left = 0, right = nums.size() - 1;
  if (nums[left] < nums[right]){
    return nums[0];
  }
  int mid = 0;
  while (left < right){
    mid = left + (right - left) / 2;

    if (nums[mid] > nums[mid + 1]){
      return nums[mid + 1];
    }
    if (nums[mid] < nums[mid - 1]){
      return nums[mid];
    }
    if (nums[mid] < nums[0]){
      right = mid - 1;
    }else {
      left = mid + 1;
    }
  }
  return -1;
}