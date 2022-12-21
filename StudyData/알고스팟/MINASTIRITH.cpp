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

bool Used[101];
int N;
struct Point
{
    float x, y, r;
    Point(float pX, float pY, float pR)
    : x(pX)
    , y(pY)
    , r(pR)
    {
    }
};

vector<Point> points;
int maxRpointIdx()
{
    int maxValue = -1;
    int idx = -1;
    for (int i = 0; i < N; i++)
    {
        if (points[i].r > maxValue)
        {
            maxValue = points[i].r;
            idx = i;
        }
    }
    return idx;
}
int maxRpointIdx(float lx, float ly, float rx, float ry)
{
    int maxValue = -1;
    int idx = -1;
    for (int i = 0; i < N; i++)
    {
        if (points[i].r > maxValue)
        {
            maxValue = points[i].r;
            idx = i;
        }
    }
    return idx;
}
void DFS(float lx, float ly, float rx, float ry)
{

}

void F()
{
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        float x, y, r;
        std::cin >> x >> y >> r;
        points.emplace_back(x, y, r);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int C;
    std::cin >> C;
    while (C--)
    {
        F();
    }

}