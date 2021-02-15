// 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。

// 请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int> > merge(vector<vector<int>>& intervals) {
  // 返回多维数组
  if (intervals.size() == 0){
    return {};
  }
  vector<vector<int> > ret;
  sort(intervals.begin(), intervals.end());
  for (int i = 0; i != intervals.size(); ++i){
    int L = intervals[i][0];
    int R = intervals[i][1];
    // 当为空时，直接加入
    if (!ret.size() || ret.back()[1] < L){
      ret.push_back({L, R});
    }else{
      ret.back()[1] = max(ret.back()[1], R);
    }
  }
  return ret;
}

int main(){
  vector<vector<int> > intervals = {{1,2}, {2,4}, {5, 6}};
  vector<vector<int> > ret = merge(intervals);
  for (auto x : ret){
    cout << x[0] << " " << x[1] << endl;
  }
}