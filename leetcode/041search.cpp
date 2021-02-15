// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。


// 二分查找
#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target){
  int len = nums.size();
  int L = 0; 
  int R = len - 1;
  int mid = 0;
  while (L <= R){
    mid = L + (R - L) / 2;
    if (nums[mid] == target){
      return mid;
    }else if(nums[mid] < target){
      L = mid + 1;
    }else{
      R = mid - 1;
    }
  }
  return -1;
}

int main(){
  vector<int> nums{-1};
  int target = -1;
  int ret = search(nums, target);
  cout << ret << endl;
}