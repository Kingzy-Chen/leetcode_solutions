#include <iostream>
#include <vector>
using namespace std;


/*暴力法*/
vector<int> searchRange_v1(vector<int>& nums, int target)
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


/*二分查找法*/
int getLeftBorder(vector<int>& nums, int target)
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    int border = -2;

    while (left <= right)
    {
        int mid = (right - left) / 2 + left;
            
        // 左边界 k 是满足 k < target 的最大 k 值
        if (nums[mid] >= target) {
            right = mid - 1;
            border = right;  // 更新 right 变量, 从而向左搜索 k 值
        }
        else {
            left = mid + 1;
        }
    }
    return border;
}


int getRightBorder(vector<int>& nums, int target)
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    int border = -2;

    while (left <= right)
    {
        int mid = (right - left) / 2 + left;

        // 右边界是满足 k > target 的最小 k 值
        if (nums[mid] <= target) {
            left = mid + 1;
            border = left;  // 更新 left 变量, 从而向右搜索 k 值
        }
        else {
            right = mid - 1;
        }
    }
    return border;
}


vector<int> searchRange_v2(vector<int>& nums, int target)
{
    int leftBorder = getLeftBorder(nums, target);
    int rightBorder = getRightBorder(nums, target);
    // cout << leftBorder << " " << rightBorder << endl;

    if (leftBorder == -2 || rightBorder == -2) return {-1, -1};  // {3, 4, 5} 查找 2 或 10 的情况, 两边界有其一不被更新
    if (rightBorder - leftBorder == 1) return {-1, -1};  // {3, 5, 6} 查找 4 的情况, 两边界只相差 1
    return {leftBorder + 1, rightBorder - 1};  // 因为是严格大于小于, 所以要 +1 和 -1
}


int main()
{
    vector<int> nums1 = {3, 6, 6, 6, 7};
    int target1 = 6;
    vector<int> ans1 = searchRange_v1(nums1, target1);
    cout << ans1[0] << " " << ans1[1] << endl;

    vector<int> nums2 = {4, 5, 6, 7, 7, 9};
    int target2 = 7;
    vector<int> ans2 = searchRange_v2(nums2, target2);
    cout << ans2[0] << " " << ans2[1] << endl;

    vector<int> nums3 = {};
    int target3 = 0;
    vector<int> ans3 = searchRange_v2(nums3, target3);
    cout << ans3[0] << " " << ans3[1] << endl;

    return 0;
}