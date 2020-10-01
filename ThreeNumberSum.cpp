#include <bits/stdc++.h>
using namespace std;

//can use two sum with target as k-a[i] and array from i+1 to n and use set to remove duplicate triplets for duplicate numbers O(N^2)

//can use 2 pointer as for two sums with left and right pointer along with target k-a[i] O(N^2)

//O(N^2)
vector<vector<int>> solve(vector<int> nums, int k)
{
    vector<vector<int>> res;
    int n = nums.size();
    if (n < 3)
        return {};
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; i++)
    {
        int target = nums[i];
        int left = i + 1;
        int right = n - 1;
        while (left < right)
        {
            if (target + nums[left] + nums[right] == k)
            {
                res.push_back({target, nums[left], nums[right]});
                left++;
            }
            else if (target + nums[left] + nums[right] < k)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return res;
}

int main()
{

    int k = 0;
    vector<int> nums{12, 3, 1, 2, -6, 5, -8, 6};
    vector<vector<int>> res = solve(nums, k);
    for (auto i : res)
        cout << i[0] << " " << i[1] << " " << i[2] << "\n";
    return 0;
}