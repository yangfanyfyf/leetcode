// 给定两个字符串 s 和 t，判断它们是否是同构的。

// 如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。

// 每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。

// 一个作为key，另外一个作为value？
#include <string>
#include <unordered_map>
using namespace std;

// 需要两张哈希表，要保证两侧的映射都是独立的
// 只用一个不能够保证badc 和 baba这种
bool isIsomorphic(string s, string t) {
  int len = s.size();
  unordered_map<char, char> hashtable;
  for (int i = 0; i != len; ++i){
    auto it = hashtable.find(s[i]);
    if (it != hashtable.end()){
      if (it->second != t[i]) return false;
    }else{
      hashtable.insert(make_pair(s[i], t[i]));
    }
  }
  return true;
}

// 同时维护两张表
bool isIsomorphic(string s, string t) {
  int len = s.size();
  unordered_map<char, char> s2t;
  unordered_map<char, char> t2s;
  for (int i = 0; i != len; ++i){
    char x = s[i], y = t[i];
    if ((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x)){
      return false;
    }
    s2t[x] = y;
    t2s[y] = x;
  }
  return true;
}