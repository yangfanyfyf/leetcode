// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。


#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
      int left = 0, right = height.size() - 1;
      int ret = 0;
      int left_max = 0, right_max = 0;
      while (left < right){
        if (height[left] < height[right]){
          if (height[left] >= left_max){
            left_max = height[left];
          }else{
            ret += (left_max - height[left]);
          }
          ++left;
        }else{
          if (height[right] >= right_max){
            right_max = height[right];
          }else{
            ret += (right_max - height[right]);
          }
          --right;
        }
      }
      return ret;
    }
};