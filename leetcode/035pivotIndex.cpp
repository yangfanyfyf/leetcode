// 给你一个整数数组 nums，请编写一个能够返回数组 “中心索引” 的方法。

// 数组 中心索引 是数组的一个索引，其左侧所有元素相加的和等于右侧所有元素相加的和。

// 如果数组不存在中心索引，返回 -1 。如果数组有多个中心索引，应该返回最靠近左边的那一个。

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
// 从两端开始相加？
// int pivotIndex(vector<int>& nums){
//   int len = nums.size();
//   if (len == 0) return -1;
//   int start = 0;
//   int sumStart = 0;
//   int end = len - 1;
//   int sumEnd = 0;
//   // 初始化sum，使循环从小的一段开始
//   if (nums[start] < nums[end]){
//       sumStart += nums[start++];
//   }else{
//       sumEnd += nums[end--];
//   }
//   // 只适用于最后和为正数时
//   while (start < end){
//     if (sumStart < sumEnd){
      
//       sumStart += nums[start++];
//       cout << "## " << sumStart << endl;

//     }else{
      
//       sumEnd += nums[end--];
//       cout << "$$ " << sumEnd << endl;

//     }
//   }
//   if (sumStart == sumEnd){
//     return start;
//   }else{
//     return -1;
//   }
// }

int pivotIndex(vector<int> &nums){
  int total = accumulate(nums.begin(), nums.end(), 0);
  int sum = 0;
  for (int i = 0; i != nums.size(); ++i){
    if (2 * sum + nums[i] == total){
      return i;
    }
    sum += nums[i];
  }
  return -1;
}




int main(){
  vector<int> nums{-1,-1,-1,-1,-1,0};
  int ret = pivotIndex(nums);
  cout << ret << endl;
  return 0;
}