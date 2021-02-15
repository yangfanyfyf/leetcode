// 模板1，基础形式

int binarySearch(vector<int> &nums, int target) {
  if (nums.size() == 0)
    return -1;
  
  int left = 0;
  int right = nums.size() - 1;
  while (left <= right){
    int mid = left + (right - left) / 2;
    if (nums[mid] == target){
      return mid;
    }else if(nums[mid] < target){
      left = mid + 1;
    }else{
      right = mid - 1;
    }
  }
  return -1;
}


// 模板2，用于查找当前索引及其直接右邻居索引的元素或者条件
int binarySearch(vector<int> &nums, int target){
  if (nums.size() == 0){
    return -1;
  }

  int left = 0;
  int right = nums.size();
  while (left < right){
    int mid = left + (right - left) / 2;
    if (nums[mid] == target){
      return mid;
    }else if(nums[mid] < target){
      left = mid + 1;
    }else{
      right = mid;
    }
  }
  // 当查找到最后两个元素时，mid == left
  if (left != nums.size() && nums[left] == target){
    return left;
  }
  return -1;
}