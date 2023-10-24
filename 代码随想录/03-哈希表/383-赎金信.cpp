#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;


bool canConstruct(string ransomNote, string magazine) 
{
	unordered_map<char, int> mp;
	
	for (auto c: magazine) mp[c] += 1;
	for (auto c: ransomNote) {
		if (mp[c] == 0) return false;
		else mp[c] -= 1;
	}
	return true;
}


int main()
{
	string ransomNote = "aa";
	string magazine = "aab";
	cout << canConstruct(ransomNote, magazine) << endl;

	return 0;
}