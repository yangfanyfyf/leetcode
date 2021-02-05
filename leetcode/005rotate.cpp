// 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

#include <iostream>
#include <vector>
using namespace std;

#define DEBUG


// 使用另外一个数组来存储
// 取余确定新位置
void rotate(vector<int> &nums, int k){
  vector<int> temp(nums.size());
  for (int i = 0; i != nums.size(); ++i){
    temp[(i + k) % nums.size()] = nums[i];
    cout << temp[(i + k) % nums.size()] << endl;
  }
  #ifdef DEBUG
  cout << "################" << endl;
  for (auto it = temp.begin(); it != temp.end(); ++it){
    cout << *it << " ";
  }
  cout << endl;
  #endif
  nums.assign(temp.begin(), temp.end());
}

// 数组翻转
void reverse(vector<int> &nums, int start, int end){
  while(start < end){
    swap(nums[start], nums[end]);
    ++start;
    --end;
  }
}

void rotate2(vector<int> &nums, int k){
  int endNum = nums.size() - 1;
  reverse(nums, 0, endNum);
  
  int num1 = (nums.size() - 1) != 0 ? k % nums.size() - 1 : 0;
  reverse(nums, 0, num1);
  
  int num2 =  k % nums.size();
  reverse(nums, num2, endNum);
}


// 环状替换
// 求取最大公约数
int gcd(int num1, int num2){
  int r = 0;
  while (num2 > 0){
    r = num1 % num2;
    num1 = num2;
    num2 = r;
  }
  return num1;
}

void rotate3(vector<int> &nums, int k){
  int n = nums.size();
  k = k % n;
  int count = gcd(k, n);
  for (int i = 0; i != count; ++i){
    // 初始位置
    int current = i;
    // 记录被替换的数
    int prev = nums[i];
    do {
      // 下一个位置
      int next = (current + k) % n;
      // 交换
      swap(nums[next], prev);
      // 更新指向的位置
      current = next;
    }while (i != current);
  }
}



int main(){
  vector<int> nums = {1, 2, 3};
  rotate3(nums, 1);


  #ifdef DEBUG
  cout << "################" << endl;
  for (auto it = nums.begin(); it != nums.end(); ++it){
    cout << *it << " ";
  }
  #endif
  return 0;
}