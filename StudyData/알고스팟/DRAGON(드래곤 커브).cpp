#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

#define Debug(a,b) cout << a << " " << b << endl
#define Init(a,b) memset(a,b,sizeof(a))

const float INF = 1e10;
const int Dic[8][2] = { {0,1},{0,-1},{1,0},{-1,0} ,{1,1},{-1,-1},{1,-1},{-1,1} };

//////////////////////////////////////////////////////////////////////// 

vector<string> Arr;

const int M = 10000000100;

int DP_Y[50];
int DP_X[50];
int DP_x(int a);
int DP_y(int a);

int DP_x(int a)
{
    if (DP_X[a] != 0)
        return DP_X[a];
    if (a == 0)
        return DP_X[a] = 1;
    return DP_X[a] = min(M, DP_x(a - 1) + DP_y(a - 1) + 2);
}
int DP_y(int a)
{
    if (DP_Y[a] != 0)
        return DP_Y[a];
    if (a == 0)
        return DP_Y[a] = 1;
    return DP_Y[a] = min(M, DP_x(a - 1) + DP_y(a - 1) + 2);
}

char GetChar(string s,int a, int p)
{
    if (a == 0)
    {
        return s[p];
    }
    int len = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'X')
        {
            int xValue = DP_x(a);
            len += xValue;

            if (len > p)
            {
                return GetChar("X+YF", a - 1, p - (len - xValue));
            }
        }
        else if (s[i] == 'Y')
        {
            int yValue = DP_y(a);
            len += yValue;
            if (len > p)
            {
                return GetChar("FX-Y", a - 1, p - (len - yValue));
            }
        }
        else 
        {
            len += 1;
            if (len > p)
            {
                if(s[i] == '+')
                    return GetChar("+",a - 1, p - (len - 1));
                else if (s[i] == '-')
                    return GetChar("-", a - 1, p - (len - 1));
                else if (s[i] == 'F')
                    return GetChar("F", a - 1, p - (len - 1));
            }
        }
    }
}

int C;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    std::cin >> C;
    while (C--)
    {
        int n, p, l;
        std::cin >> n >> p >> l;
        p--;
        for (int i = 0; i < l; i++)
        {
            std::cout << GetChar("FX", n, p + i);
        }
        std::cout << endl;
    }

}