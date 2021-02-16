#include <unordered_set>
#include <iostream>
using std::unordered_set;
using std::cout;
using std::endl;
int main(){
  unordered_set<int> hashset;
  // 向哈希表中增加键
  hashset.insert(3);
  hashset.insert(2);
  hashset.insert(1);
  // 删除键
  hashset.erase(2);
  // count用于计数，但是哈希集合不允许重复值，所以这里用于检查容器中是否有对应的元素
  if (!hashset.count(2)){
    cout << "Key 2 is not inside hashset" << endl;
  }
  // 哈希表大小
  cout << "size of hashset: " << hashset.size() << endl;
  // 遍历
  for (auto it = hashset.begin(); it != hashset.end(); ++it){
    cout << (*it) << " ";
  }
  cout << endl;
  // 清除
  hashset.clear();
  // 
  if (hashset.empty()){
    cout << "hashset is empty! " << endl;
  }
}