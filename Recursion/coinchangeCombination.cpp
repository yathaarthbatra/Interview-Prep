#include <bits/stdc++.h>
using namespace std;

//Combinations:n Selection
//in this we take an index that keeps the record the elements you can use

// -->Combination infinite(Same coin can be used multiple times)
// -->Combination Single(one coin can be used only one time)

int coinChangeCombinInfi(int target, int arr[], int n, int idx, string ans)
{

    //base case:
    if (target == 0)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;

    for (int i = idx; i < n; i++)
    {
        if (target - arr[i] >= 0)
        {
            count += coinChangeCombinInfi(target - arr[i], arr, n, i, ans + to_string(arr[i]));
        }
    }
    return count;
}

//One coin can be used single time
int coinChangeCombin(int target, int arr[], int n, int idx, string ans)
{

    //base case:
    if (target == 0)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;

    for (int i = idx; i < n; i++)
    {
        if (target - arr[i] >= 0)
        {
            count += coinChangeCombinInfi(target - arr[i], arr, n, i + 1, ans + to_string(arr[i]));
        }
    }
    return count;
}

int main()
{

    int arr[] = {2, 3, 5, 7};
    cout << coinChangeCombinInfi(10, arr, 4, 0, "");
    cout << "----" << endl;

    cout << coinChangeCombin(10, arr, 4, 0, "");

    return 0;
}