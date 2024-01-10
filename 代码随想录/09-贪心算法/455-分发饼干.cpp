#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int findContentChildren(vector<int>& g, vector<int>& s) 
{
	// 将饼干和胃口排序
	sort(g.begin(), g.end(), less<int>());
	sort(s.begin(), s.end(), less<int>());

	int ans = 0;
	int i = 0;
	int j = 0;

	// 小饼干优先喂小胃口
	while (i < g.size() && j < s.size()) 
	{
		if (s[j] >= g[i]) {
			ans += 1;
			i++;
			j++;
		}
		else {j++;}
	}
	return ans;
}


int main()
{
	vector<int> g1 = {1, 2, 3};
	vector<int> s1 = {1, 1};
	cout << findContentChildren(g1, s1) << endl;

	vector<int> g2 = {1, 2};
	vector<int> s2 = {1, 2, 3};
	cout << findContentChildren(g2, s2) << endl;

	return 0;
}