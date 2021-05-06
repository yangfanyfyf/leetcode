// 给定一个非负整数数组 nums 和一个整数 m ，你需要将这个数组分成 m 个非空的连续子数组。

// 设计一个算法使得这 m 个子数组各自和的最大值最小。


class Solution {
public:
    // 不比较每个数组的值
    // 统计所有不大于指定数字的集合的数目
    bool check(vector<int> &nums, int m, int mid){
      long long sum = 0;
      int cnt = 1;
      for (int i = 0; i < nums.size(); ++i){
        if (sum + nums[i] > mid){
          ++cnt;
          sum = nums[i];
        } else {
          sum += nums[i];
        }
      }
      // 要求的是true
      // 返回false表明这个数字太小了
      // 枚举更大的数字
      return cnt <= m;
    }
    int splitArray(vector<int>& nums, int m) {
      // 先找出最大值，以及所有书的和
      long long maxNum = 0, sumNum = 0;
      for (auto p : nums){
        sumNum += p;
        if (p > maxNum){
          maxNum = p;
        }
      }
      // 二分搜索
      while (maxNum < sumNum){
        long long mid = maxNum + (sumNum - maxNum) / 2;
        if (!check(nums, m, mid)){
          maxNum = mid + 1;
        }else {
          sumNum = mid;
        }
      }
      return maxNum;
    }
};