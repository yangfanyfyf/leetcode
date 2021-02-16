#include <iostream>
#include <unordered_map>
#include <utility>
using std::unordered_map;
using std::make_pair;
using std::cout;
using std::endl;

int main(){
  unordered_map<int, int> hashmap;
  // 插入
  hashmap.insert(make_pair(0, 0));
  hashmap.insert(make_pair(2, 3));
  // 修改key对应的值？
  hashmap[1] = 1;
  hashmap[1] = 2;
  // 访问值
  cout << "the value of key 1 is : " << hashmap[1] << endl;
  // 删除
  hashmap.erase(2);

  if (hashmap.count(2) <= 0){
    cout << "键2不在哈希表中" << endl;
  }
  cout << "哈希表的大小: " << hashmap.size() << endl;
  for (auto it = hashmap.begin(); it != hashmap.end(); ++it){
    cout << "(" << it->first << ", " << it->second << ")" << endl;
  }

  hashmap.clear();
  if(hashmap.empty()){
    cout << "哈希表为空！" << endl;
  }

}