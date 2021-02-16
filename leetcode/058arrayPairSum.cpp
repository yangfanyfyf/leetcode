// 给定长度为 2n 的整数数组 nums ，你的任务是将这些数分成 n 对, 例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从 1 到 n 的 min(ai, bi) 总和最大。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 先排序，然后两两组合？
int arrayPairSum(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  int sum = 0;
  for (int i = 0; i != nums.size(); i += 2){
    sum += min(nums[i], nums[i + 1]);
  }
  return sum;
}

int main(){
  vector<int> nums{6,2,6,5,1,2};
  int m = arrayPairSum(nums);
  cout << "最大值是：" << m << endl;
}