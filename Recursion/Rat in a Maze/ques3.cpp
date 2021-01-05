//ques: To count & print paths from start to des(one jump at a time)
//now we can move in all directions top bottom right left diagonally 8 directions
//Here we will require lot of effort to have 8 calls so we will require driection array
//direction array will contain directions the person can move
//here we also have to take visited array so that it cant make loop

#include <bits/stdc++.h>
using namespace std;

int printPaths(int sr, int sc, int dr, int dc, int dir[][2], int d, bool **vis, int n, int m, string names[], string psf)
{
    //n and m are rows and columns of the matrix
    //base case:
    if (sr == dr && sc == dc)
    {
        cout << psf << endl;
        return 1;
    }

    vis[sr][sc] = true;

    int count = 0;

    //no we will traverse the direction array and acc we will move in those dxns
    for (int i = 0; i < d; i++)
    {
        int r = sr + dir[i][0];
        int c = sc + dir[i][1];

        //to check whether it doesnot goes out of the boundary
        if (r >= 0 && c >= 0 && r < n && c < m && !vis[r][c])
        {
            count += printPaths(r, c, dr, dc, dir, d, vis, n, m, names, psf + names[i]);
        }
    }
    vis[sr][sc] = false;
    //in case of backtracking we must do it false
    //otherwise other points will not get the paths
    return count;
}

int main()
{
    //to make a visited array which has by default all the values false
    bool **visited = new bool *[3];
    for (int i = 0; i < 3; i++)
    {
        visited[i] = new bool[3];
        for (int j = 0; j < 3; j++)
        {
            visited[i][j] = false;
        }
    }
    //               H      D     V
    int dir[3][2] = {{0, 1}, {1, 1}, {1, 0}};

    string names[] = {"H", "D", "V"};
    cout << printPaths(0, 0, 2, 2, dir, 3, visited, 3, 3, names, "") << endl;
}