#include <bits/stdc++.h>
using namespace std;

//print Decreasing number from n to 1
void Decreasing(int[] arr, int n)
{

    //base case:
    //in case of rec whenever a return is fired then the flow of rec becomes opposite
    if (n == 0)
    {
        return;
    }

    cout << n << endl;
    Decreasing(n - 1); //Faith => it will print the elements from 1 to n-1 in dec order
}

//print increasing order from 1 to n
void Increasing(int n)
{

    //base case:
    if (n == 0)
    {
        return;
    }

    Increasing(n - 1);
    cout << n << endl;
}

//decreasing(even)Increasing(odd)
// 10 8 6 4 2 1 3 5 7 9 ..given n=10
void decInc(int n)
{
    //base case:
    if (n == 0)
    {
        return;
    }
    if (n % 2 == 0)
    {
        cout << n << endl;
    }
    decInc(n - 1); //Faith that it will  print the
    //dec and inc of even and odd element from 1 to n-1
    if (n % 2 == 1)
    {
        cout << n << endl;
    }
}

//power ==> (a,b)
int power(int a, int b)
{
    //base case:
    if (b == 0)
        return 1;
    int ans = power(a, b - 1);
    return (ans * a);
}
