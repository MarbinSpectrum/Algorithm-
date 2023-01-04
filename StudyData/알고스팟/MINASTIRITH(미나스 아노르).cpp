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

int N;
vector<pair<float, float>> lens;

void F()
{
    lens.clear();
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        float x, y, r;
        std::cin >> x >> y >> r;

        float Ry = r / 2.;
        float Rx = sqrt(64 - Ry * Ry);
        float angle = (float)(57.295779513082323 * atan2(Ry, Rx)) * 4;
        float bAngle = (float)(57.295779513082323 * atan2(y, x));

        if (bAngle < 0)
            bAngle = bAngle + 360;

        float sAngle = bAngle - angle / 2.0;
        float eAngle = bAngle + angle / 2.0;

        sAngle = fmod(sAngle + 360.0, 360.0);
        eAngle = fmod(eAngle + 360.0, 360.0);

        lens.emplace_back(sAngle, eAngle);
    }

    sort(lens.begin(), lens.end());

    int ans = INF;
    for (int i = 0; i < N; i++)
    {
        float a = lens[i].first;
        float b = lens[i].second;
        int cnt = 1;

        if (b <= a)
        {
            int idx = 0;
            float m = -1;
            while (b < a)
            {
                while (idx < N && lens[idx].first <= b)
                {
                    if (lens[idx].first > lens[idx].second)
                        m = max(m, lens[idx].second + 360);
                    else
                        m = max(m, lens[idx].second);
                    idx++;
                }

                if (m <= b)
                {
                    cnt = INF;
                    break;
                }
                else
                {
                    b = m;
                    cnt++;
                }
            }
            ans = min(ans, cnt);
        }

    }

    if (ans != INF)
        std::cout << ans << endl;
    else
        std::cout << "IMPOSSIBLE" << endl;
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