#include<iostream>
#include<vector>
using namespace std;

// 计数排序

void sortArray(vector<int> &nums){
  int len = nums.size();
  int max = nums[0];
  for (int i = 1; i != len; ++i){
    // 找到最大值
    if (nums[i] > max ){
      max = nums[i];
    }
    if (nums[i] < 0){
      cout << "negative number, use another method" << endl;
    }
  }
  // 计数
  vector<int> count (max + 1);
  // 遍历原始数组，完成计数
  for (int i = 0; i != len; ++i){
    ++count[nums[i]];
  }
  // 前缀和数组
  for (int i = 1; i <= max; ++i){
    count[i] += count[i - 1];
  }
  // 复制一遍原来的数组，然后从后向前，按照指定的顺序放回原数组中
  vector<int> numsCopy = nums;
  for (int i = len - 1; i >= 0; --i){
    int position = count[numsCopy[i]] - 1;
    nums[position] = numsCopy[i];
    count[numsCopy[i]]--;
  }
}

int main(){
  vector<int> nums = {2, 5, 3, 0, 2, 3, 0, 3};
  sortArray(nums);
  for (auto p : nums){
    cout << p << ' ';
  }
  cout << endl;
}