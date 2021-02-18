// 给定一个含有 n 个正整数的数组和一个正整数 target 。

// 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// class Solution {
// public:
    // int minSubArrayLen(int target, vector<int>& nums) {
    //   // 遍历，求两个指针之间的数字的和
    //   int start = 0, end = 0;
    //   int idx = nums.size();
    //   int sum = 0;
    //   while (end <= nums.size()){
    //     // sum += nums[end]; 
    //     // 记录长度
    //     if(sum == target){
    //       idx = min(idx, end - start);
    //       sum -= nums[start++];
    //     }else if (sum < target){
    //       if (end == nums.size() && idx == nums.size()){
    //         return 0;
    //       }
    //       if (end == nums.size()) break;
    //       sum += nums[end++];
    //     }else{
    //       sum -= nums[start++];
    //     }
    //     // cout << idx << endl;
    //   }
    //   return idx;
    // }
// };

int minSubArrayLen(int s, vector<int>& nums) {
  int n = nums.size();
  if (n == 0) return 0;

  int ans = INT_MAX;
  int start = 0, end = 0;
  int sum = 0;
  while (end < n){
    sum += nums[end];
    // 当sum的值超过指定值时，开始递减
    while (sum >= s) {
      ans = min(ans, end - start + 1);
      sum -= nums[start];
      ++start;
    }
    ++end;
  }
  return ans == INT_MAX ? 0 : ans;
}







int main(){
  vector<int> nums{1,1,1,1,1,1,1,1};
  int k = minSubArrayLen(11, nums);
  cout << k << endl;
}