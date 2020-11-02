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

double a, b, c;
double AF, BD;
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);

    cin >> a >> b >> c;
    cin >> AF >> BD;

    double alpha = BD / (a - BD) * AF / (c - AF);
    printf("%.13lf\n", b / (alpha + 1));
}