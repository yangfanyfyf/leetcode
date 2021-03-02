// 设计一个找到数据流中第 k 大元素的类（class）。注意是排序后的第 k 大元素，不是第 k 个不同的元素。

// 请实现 KthLargest 类：

// KthLargest(int k, int[] nums) 使用整数 k 和整数流 nums 初始化对象。
// int add(int val) 将 val 插入数据流 nums 后，返回当前数据流中第 k 大的元素。


class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int> > q;
    int k;
    KthLargest(int k, vector<int>& nums) {
      this->k = k;
      for (auto x : nums)
        add(x);
    }
    
    int add(int val) {
        q.push(val);
        // 将大小限制为k
        if (q.size() > k){
            q.pop();
        }
        return q.top();
    }
};