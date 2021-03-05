// 选择排序
// 超时
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
      int n = nums.size();
      if (n == 0){
        return {};
      }
      int min = 0;
      for (int i = 0; i != n; ++i){
        min = nums[i];
        int minIndex = i;
        for (int j = i; j != n; ++j){
          if (nums[j] < min){
            min = nums[j];
            minIndex = j;
          }
        }
        int temp = nums[minIndex];
        nums[minIndex] = nums[i];
        nums[i] = temp;
      }
      return nums;
    }
};
