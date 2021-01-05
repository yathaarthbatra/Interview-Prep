#include <bits/stdc++.h>
using namespace std;

//ques: Print and count possible paths from start to des
//we can only move 3 dxns H,V,D
//one jump at a time

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
    if (sc + 1 <= dc)
    {
        count += printPaths(sr, sc + 1, dr, dc, ans + "H");
    }
    //move diagnolly sr+1,sc+1
    if (sc + 1 <= dc && sr + 1 <= dr)
    {
        count += printPaths(sr + 1, sc + 1, dr, dc, ans + "D");
    }
    if (sr + 1 <= dr)
    {
        count += printPaths(sr + 1, sc, dr, dc, ans + "V");
    }
    return count;
}

int main()
{

    cout << printPaths(0, 0, 2, 2, "");
}