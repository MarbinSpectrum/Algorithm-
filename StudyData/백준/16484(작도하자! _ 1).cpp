﻿#include<iostream>
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

double n, d;
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);

    cin >> n >> d;

    printf("%.1lf\n", n / 2 - d);
}