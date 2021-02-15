// 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

// 需要跳过数组已经排序的部分

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// int findKthLargest(vector<int>& nums, int k) {
//   if (nums.size() == 1 && k == 1){
//     return nums[0];
//   }
//   sort(nums.begin(), nums.end());
//   int n = 1;
//   for (int i = 1; i != nums.size(); ++i){
//     if (nums[i] != nums[i - 1]){
//       ++n;
//     }
//     if ( n == k){
//       return nums[i];
//     }
//   }
//   return -1;
// }


int findKthLargest(vector<int>& nums, int k) {
  sort(nums.rbegin(), nums.rend());
  return nums[k - 1];
}


int main(){
  vector<int> nums{3,2,3,1,2,4,5,5,6};
  int ret = findKthLargest(nums, 4);
  cout << ret << endl;
}