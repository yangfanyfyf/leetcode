// 给定一个整数数组  nums，求出数组从索引 i 到 j（i ≤ j）范围内元素的总和，包含 i、j 两点。

// 实现 NumArray 类：

// NumArray(int[] nums) 使用数组 nums 初始化对象
// int sumRange(int i, int j) 返回数组 nums 从索引 i 到 j（i ≤ j）范围内元素的总和，包含 i、j 两点（也就是 sum(nums[i], nums[i + 1], ... , nums[j])）

// 使用前缀和

class NumArray {
public:
    vector<int> sumArray{0};
    NumArray(vector<int>& nums) {
      // 读入数组时，求和
      for (int k = 0; k != nums.size(); ++k){
        sumArray.emplace_back(nums[k] + sumArray.back());
      }
    }
    
    int sumRange(int i, int j) {
        return sumArray[j + 1] - sumArray[i];
    }
};