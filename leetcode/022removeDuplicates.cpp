// 给定一个增序排列数组 nums ，你需要在 原地 删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。

// 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

// int removeDuplicates(vector<int>& nums){
//   if (nums.size() == 0 || nums.size() == 1){
//     return nums.size();
//   }
//   int k = 1;
//   if (nums[0] == nums[1]){
//     ++k;
//   }
//   for (int i = k; i != nums.size(); ++i){
    
//     if (nums[i] != nums[i - 1]){
//       nums[k++] = nums[i];
//       if (nums[i] == nums[i+1]){
//         nums[k++] = nums[i];
//       }
//     }
//   }
//   return k;
// }

int removeDuplicates(vector<int>& nums){
  int len = 0;
  for (int i = 0; i != nums.size(); ++i){
    // 保留前两个元素
    // len - 2 是倒数第二个元素
    if (len < 2 || nums[i] != nums[len - 2]){
      nums[len++] = nums[i];
    }
  }
  return len;
}



int main(){
  vector<int> nums = {1,2};
  // moveZeroes(nums);
  int k = removeDuplicates(nums);
  for (auto x : nums){
    cout << x << " ";
  }
  cout << endl;
  cout << "length == " << k << endl;
  return 0;
}