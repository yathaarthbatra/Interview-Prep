#include <bits/stdc++.h>
using namespace std;

//Permutations means : Arrangement
//Combinations means : Selection

//Permutations of the coins to get a target

// -->Permutation infinite(Same coin can be used multiple times)
// -->Permutation Single(one coin can be used only one time)

//Coins are 2 3 5 7 and target = 10

//First fun: To count and Print different Permutations with infinite calls

int coinChangePermutInfi(int target, int arr[], int n, string ans)
{

    //ans will contain different permuations and we will print them once base case is hit
    //base case:
    if (target == 0)
    {
        cout << ans << endl;
        return 1; //We got one Permuataion
    }

    int count = 0; //will store the count of total permutations

    for (int i = 0; i < n; i++)
    {
        if (target - arr[i] >= 0)
        {
            count += coinChangePermutInfi(target - arr[i], arr, n, ans + to_string(arr[i]));
        }
    }
    return count;
}

//Now single coin can be used
int coinChangePermut(int target, int arr[], int n, string ans)
{

    //base case
    if (target == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int ele = arr[i];

        if (arr[i] > 0 && target - ele >= 0)
        {
            arr[i] = -arr[i];
            count += coinChangePermut(target - ele, arr, n, ans + to_string(ele));
            arr[i] = -arr[i];
        }
    }
    return count;
}

int main()
{
    int arr[] = {2, 3, 5, 7};
    cout << coinChangePermutInfi(10, arr, 4, "");
    cout << endl
         << "--" << endl;
    cout << coinChangePermut(10, arr, 4, "");
}