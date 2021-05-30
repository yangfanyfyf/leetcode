// 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

// 找出面积最大的矩形

// 暴力求解，超时
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) { 
      // 选择一个柱子，像两边进行延展
      int n = heights.size();
      int ans = 0;
      for (int mid = 0; mid != n; ++mid){
        int tempHeight = heights[mid];
        int left = mid, right = mid;
        while (left - 1 >= 0 && heights[left - 1] >= tempHeight){
          --left;
        }
        while (right + 1 < n && heights[right + 1] >= tempHeight){
          ++right;
        }
        ans = max(ans, tempHeight * (right - left + 1));
      }
      return ans;
    }
};


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) { 
      int n = heights.size();
      vector<int> left(n), right(n);
      stack<int> mono_stack;
      for (int i = 0; i != n; ++i){
        while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]){
          mono_stack.pop();
        }
        left[i] = mono_stack.empty() ? -1 : mono_stack.top();
        mono_stack.push(i);
      }

      mono_stack = stack<int>();
      for (int i = n - 1; i >= 0; --i){
        while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]){
          mono_stack.pop();
        }
        right[i] = (mono_stack.empty() ? n : mono_stack.top());
        mono_stack.push(i);
      }
      int ans = 0;
      for (int i = 0; i != n; ++i){
        ans = max (ans, (right[i] - left[i] - 1) * heights[i]);
      }
      return ans;
    }
};