#include <bits/stdc++.h>

#pragma warning(disable:4996)

using namespace std;

#define endl "\n"
#define int long long
#define float long double

#define Debug(a,b) cout << a << " " << b << endl
#define Init(a,b) memset(a,b,sizeof(a))

const float INF = 1e18;
const int Dic[8][2] = { {0,1},{0,-1},{1,0},{-1,0} ,{1,1},{-1,-1},{1,-1},{-1,1} };

//////////////////////////////////////////////////////////////////////// 

int N, M;
vector<tuple<float, int, int>> Star;
int ans = -INF;
float GetAngleDis(int l, int r)
{
    float v = get<0>(Star[r]) - get<0>(Star[l]);
    if (v < 0)
        v = fmod(v + 360.0, 360.0);
    return v;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    std::cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int x, y, s;
        std::cin >> x >> y >> s;
        float angle = (float)(180.0 / (atan(1) * 4) * atan2(y, x));
        angle = fmod(angle + 360.0, 360.0);
        Star.emplace_back(angle, x * x + y * y, s);
    }

    sort(Star.begin(), Star.end());

    for (int i = 0; i < M; i++)
    {
        int a;
        std::cin >> a;
        int l = 0;
        int ret = 0;
        for (int r = 0; r < N * 2; r++)
        {
            int nl = l % N;
            int nr = r % N;

            while (GetAngleDis(nl, nr) > 90)
            {
                float lDis = get<1>(Star[nl]);
                float lValue = get<2>(Star[nl]);
                if (a >= lDis)
                {
                    ret -= lValue;
                    ans = max(ans, ret - a);
                }
                l++;
                nl = l % N;
            }

            float rDis = get<1>(Star[nr]);
            float rValue = get<2>(Star[nr]);
            if (a >= rDis)
            {
                ret += rValue;
                ans = max(ans, ret - a);
            }
        }
        ans = max(ans, 0 - a);
    }

    std::cout << ans << endl;

}