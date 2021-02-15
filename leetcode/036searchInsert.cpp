// 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

// 你可以假设数组中无重复元素。

// 可以直接用find吗？

// 数组已经排序，可以直接从头开始搜索？
#include <iostream>
#include <vector>
using namespace std;

// 顺序查找
// int searchInsert(vector<int>& nums, int target){
//   if (nums.size() == 0){
//     return 0;
//   }
//   if (target > nums[nums.size() - 1]){
//     return nums.size();
//   }
//   for (int i = 0; i != nums.size(); ++i){
//     if (nums[i] == target){
//       return i;
//     }
//     if (nums[i] > target){
//       return i;
//     }
//   }
//   return -1;
// }
// 二分查找
// 当只剩下两个数字时，mid == left, 仍未找到，那么返回mid + 1
int searchInsert(vector<int>& nums, int target){
  int len = nums.size();
  int left = 0;
  int right = len - 1;
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
  return left;
}

int main(){
  vector<int> nums{1,3,5,6};
  int target = 7;
  int ret = searchInsert(nums, target);
  cout << ret << endl;
}