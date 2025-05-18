#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Function to compute digit sum
int digitSum(int n)
{
    int sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Function to compute minimum number of swaps
int minSwapsToSort(vector<int> &nums)
{
    int n = nums.size();
    vector<pair<int, int>> sd;
    for (int num : nums)
    {
        sd.push_back({digitSum(num), num});
    }
    sort(sd.begin(), sd.end());
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[sd[i].second] = i;
    }
    vector<bool> vis(n, false);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] || mp[nums[i]] == i)
            continue;

        int cycleSize = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = true;
            j = mp[nums[j]];
            cycleSize++;
        }
        if (cycleSize > 1)
            cnt += (cycleSize - 1);
    }

    return cnt;
}

// Main function with examples
int main()
{
    vector<vector<int>> testCases = {
        {37, 100},
        {22, 14, 33, 7},
        {18, 43, 34, 16},
        {268835996, 65052660, 415128775}
    };

    for (auto nums : testCases)
    {
        cout << "Input: ";
        for (int num : nums)
            cout << num << " ";
        cout << "\nOutput: " << minSwapsToSort(nums) << "\n\n";
    }

    return 0;
}
