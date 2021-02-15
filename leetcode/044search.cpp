// 升序排列的整数数组 nums 在预先未知的某个点上进行了旋转（例如， [0,1,2,4,5,6,7] 经旋转后可能变为 [4,5,6,7,0,1,2] ）。

// 请你在数组中搜索 target ，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& nums, int target) {
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
// 先找到旋转点，得到两个数组，再分别进行搜索
int search(vector<int>& nums, int target) {
  int breakPoint = 0;
  vector<int> nums1;
  vector<int> nums2;
  if (nums.size() == 1){
    breakPoint = 0;
  }else{
    for (int i = 1; i != nums.size(); ++i){
      nums1.push_back(nums[i - 1]);
      if (nums[i] < nums[i - 1]){
        breakPoint = i;
        break;
      }
    }
  }
  for (int i = breakPoint; i != nums.size(); ++i){
    nums2.push_back(nums[i]);
  }
  cout << nums1.size() << endl;
  int ret1 = binarySearch(nums1, target);
  int ret2 = binarySearch(nums2, target);
  if (ret1 != -1){
    return ret1;
  }else if (ret2 != -1){
    return ret2 + breakPoint;
  }else{
    return -1;
  }
}



int main(){
  vector<int> nums{4,5,6,7,0,1,2};
  int ret = search(nums, 2);
  cout << ret << endl;
}