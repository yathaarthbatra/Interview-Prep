#include <bits/stdc++.h>
using namespace std;

//Problem : To find the pair of the elements which sum up to target

//BF: Apply 2 loops and then check the sum equal to target --> O(n^2)

//USing sorting and apply 2 pointers from start and end
//and if the repetition happens we can keep the prev and next pointers

vector<int> sum2(vector<int> &nums, int target)
{

    //using sorting
    //here we are only storing the elements which has target
    //here we are returnig only one pair
    sort(nums.begin(), nums.end());
    vector<int> ans;
    int i = 0, j = nums.size() - 1;
    while (i < j)
    {
        int sum = nums[i] + nums[j];
        if (sum > target)
            j--;
        else if (sum < target)
            i++;
        else
        {
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            return ans;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 1, 1};
    vector<int> ans = sum2(nums, 2);

    for (int a : ans)
    {
        cout << a << " ";
    }
}