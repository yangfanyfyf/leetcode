// 给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度。

// 当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

// 请计算 最多能有多少个 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
      int n = envelopes.size();
      if (n == 0){
        return 0;
      }
      sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2){
        return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
      });
      vector<int> f(n, 1);
      for (int i = 1; i != n; ++i){
        for(int j = 0; j != i; ++j){
          if (envelopes[j][1] < envelopes[i][1]){
            f[i] = max(f[i], f[j] + 1);
          }
        }
      }
      return *max_element(f.begin(), f.end());
    }
};

