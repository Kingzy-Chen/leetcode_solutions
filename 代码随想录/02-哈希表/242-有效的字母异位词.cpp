#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

/*
	set: 底层红黑树, 有序, 数值不可重复, 查询增删效率 O(logn)
	multiset: 底层红黑树, 有序, 数值可重复, 查询增删效率 O(logn)
	unordered_set: 底层哈希表, 无序, 数值不可重复, 查询增删效率 O(1)

	map: 底层红黑树, 有序, key不可重复, 查询增删效率 O(logn)
	multimap: 底层红黑树, 有序, key可重复, 查询增删效率 O(logn)
	unordered_map: 底层哈希表, 无序, key不可重复, 查询增删效率 O(1)
*/

bool isAnagram(string s, string t)
{
	unordered_map<char, int> mp;
	for (auto c: s) mp[c] += 1;
	for (auto c: t) mp[c] -= 1;

	for (auto& kv: mp) {
		if (kv.second != 0) return false;
	}
	return true;
}


int main()
{
	string s = "anagram";
	string t = "nagaram";
	cout << isAnagram(s, t) << endl;

	return 0;
}