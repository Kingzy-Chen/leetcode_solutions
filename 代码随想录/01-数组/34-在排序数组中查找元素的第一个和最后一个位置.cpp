#include <iostream>
#include <vector>
using namespace std;


vector<int> searchRange(vector<int>& nums, int target) 
{
    int n = nums.size();
    vector<int> ans = {-1, -1};

    for (int i = 0; i < n; i++) {
        if (nums[i] == target) {
            ans[0] = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (nums[i] == target) {
            ans[1] = i;
            break;
        }
    }
    return ans;
}


int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> ans = searchRange(nums, target);

    for (auto t: ans) cout << t << " ";
    cout << endl;

    return 0;
}