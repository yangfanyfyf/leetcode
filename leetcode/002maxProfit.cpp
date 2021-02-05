// 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
// 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

// 低价买入，高价卖出

// 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      if (prices.size() == 0 || prices.size() == 1){
        return 0;
      }
      int max = 0;
      // 当prices.size()等于1时，会发生越界
      // 数组越界！
      for (int i = 0; i != prices.size() - 1; ++i){
        if(prices[i] < prices[i + 1]){
          max += prices[i + 1] - prices[i];
        }
      }
      return max;
    }
};