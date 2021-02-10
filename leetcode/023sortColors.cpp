// 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

// 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

void sortColors(vector<int>& nums){
  sort(nums.begin(), nums.end());
}

int main(){
  vector<int> nums = {2,0,2,1,1,0};
  // moveZeroes(nums);
  sortColors(nums);
  for (auto x : nums){
    cout << x << " ";
  }
  cout << endl;
  // cout << "length == " << k << endl;
  return 0;
}