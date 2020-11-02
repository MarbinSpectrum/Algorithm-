#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<stack>
#include<map>
#include<set>

#pragma warning(disable:4996)

using namespace std;

long long R, r;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> r;

    cout << R * (R - 2 * r) << endl;


}