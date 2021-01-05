#include <bits/stdc++.h>
using namespace std;

//ques: Print Possible Paths from st to des
//infinite jumps allowed(1/2/3...)
//Directions allowed: H,V,D

//as we are moving only in forward direction
//so no loop will be formed
//no need to make a visited array

int printPaths(int sr, int sc, int dr, int dc, string ans)
{

    //It prints the possible paths from st to des and also brings the count
    //base case:
    if (sr == dr && sc == dc)
    {
        cout << ans << endl;
        return 1;
    }

    //in this ques we are only allowed to go forward so no cyclw will be followed

    int count = 0;
    //move horizontally but to check the boundary also
    for (int j = 1; sc + j <= dc; j++)
    {
        count += printPaths(sr, sc + j, dr, dc, ans + "H");
    }
    //move diagnolly sr+1,sc+1
    for (int j = 1; (sc + j <= dc && sr + j <= dr); j++)
    {
        count += printPaths(sr + j, sc + j, dr, dc, ans + "D");
    }
    for (int j = 1; sr + j <= dr; j++)
    {
        count += printPaths(sr + j, sc, dr, dc, ans + "V");
    }
    return count;
}

int main()
{
    cout << printPaths(0, 0, 3, 3, "");
}
