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

double r1, r2, r3;
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);

    cin >> r1 >> r2 >> r3;
    printf("%.13lf", 1 / ((1 / r1) + (1 / r2) + (1 / r3)));

}