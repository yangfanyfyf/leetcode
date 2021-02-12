// 给定一个整数数据流和一个窗口大小，根据该滑动窗口的大小，计算其所有整数的移动平均值。

#include <deque>
using std::deque;

class MovingAverage {
private:
    deque<int> windowDeq;
    int maxSize;
public:
    /** Initialize your data structure here. */
    // 初始化一个队列
    MovingAverage(int size) {
      maxSize = size;
    }
    
    double next(int val) {
      if (windowDeq.size() < maxSize){
        windowDeq.push_back(val);
        double sum = 0;
        for (auto x : windowDeq){
          sum += x;
        }
        return sum / windowDeq.size();
      }else{
        windowDeq.pop_front();
        windowDeq.push_back(val);
        double sum = 0;
        for (auto x : windowDeq){
          sum += x;
        }
        return sum / windowDeq.size();
      }
    }
};