// 给定两个数组，编写一个函数来计算它们的交集。

vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
  vector<int> temp;
  unordered_set<int> hashset;
  for(auto x : nums1){
    
    hashset.insert(x);
  }
  for (auto x : nums2){
    if (hashset.count(x) > 0){
      temp.push_back(x); // 可能存在重复元素
    }
  }
  vector<int>::iterator it = unique(temp.begin(), temp.end());
  temp.erase(it, temp.end());
  return temp;
}