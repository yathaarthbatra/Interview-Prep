#include <bits/stdc++.h>
using namespace std;

int printPermutations(string ques, string ans)
{

    //base case:
    if (ques.length() == 0)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    sort(ques.begin(), ques.end());

    for (int i = 0; i < ques.length(); i++)
    {
        char ch = ques[i];
        string ros = ques.substr(0, i) + ques.substr(i + 1);
        if (i > 0 && ques[i] == ques[i - 1])
        {
            continue;
        }
        count += printPermutations(ros, ans + ch);
    }
}

int main()
{
    int count = printPermutations("aba", "");
}