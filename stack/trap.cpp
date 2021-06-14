// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
      int ans = 0;
      stack<int> monoStack;
      int n = height.size();
      // monoStack.push(height[0]);
      for (int i = 0; i != n; ++i){
        while (!monoStack.empty() && height[i] > height[monoStack.top()]){
          // top的数字一定会比left的小
          // 所以每次while循环，都只是计算一格能容纳的水量
          int top = monoStack.top();
          monoStack.pop();
          if (monoStack.empty()){
            break;
          }
          int left = monoStack.top();
          int currWidth = i - left - 1;
          // 这里left为什么不用减去top？
          int currHeight = min(height[left] - height[top], height[i] - height[top]);
          ans += currWidth * currHeight;
        }
        monoStack.push(i);
      }
      return ans;
    }
};