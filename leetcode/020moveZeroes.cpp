// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

// 将记录0的第一个位置？将非0的数前移？需要两个循环？

// 不如将0移动到数组最后

#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums){
  int numsSize = nums.size();
  int k = 0;
  for (int i = 0; i != numsSize; ++i){
    if (nums[i]){
      nums[k++] = nums[i];
    }
  }
  for (int i = k; i != numsSize; ++i){
    nums[i] = 0;
  }
}


int main(){
  vector<int> nums = {0,1,0,3,12};
  moveZeroes(nums);
  for (auto x : nums){
    cout << x << " ";
  }
  cout << endl;
  
  return 0;
}