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
    //l과 r사이의 각도
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

        //각 별들의 각도를 전처리
        float angle = (float)(180.0 / (atan(1) * 4) * atan2(y, x));
        angle = fmod(angle + 360.0, 360.0);
        Star.emplace_back(angle, x * x + y * y, s);
    }

    //별들을 각도순으로 정렬
    sort(Star.begin(), Star.end());

    //뒤에 똑같은 별들을 연결시켜준다.
    for (int i = 0; i < N; i++)
    {
        float angle = get<0>(Star[i]);
        int dis = get<1>(Star[i]);
        int s = get<2>(Star[i]);
        Star.emplace_back(angle, dis, s);
    }

    for (int i = 0; i < M; i++)
    {
        int a;
        std::cin >> a;
        int l = 0;
        int ret = 0;
        for (int r = 0; r < N * 2; r++)
        {
            while (GetAngleDis(l, r) > 90)
            {
                //각도가 90도를 넘겼다.
                //l를 증가시킨다.
                float lDis = get<1>(Star[l]);
                float lValue = get<2>(Star[l]);
                if (a >= lDis)
                {
                    //이전에 포함했던 별이다.
                    //점수를 제거해준다.
                    ret -= lValue;
                    ans = max(ans, ret - a);
                }
                l++;
            }

            //여기까지왔으면 각도는 90도 안쪽이다.
            float rDis = get<1>(Star[r]);
            float rValue = get<2>(Star[r]);
            if (a >= rDis)
            {
                //포함시킬수 있는 별이다.
                //별들의 점수를 포함시켜준다.
                ret += rValue;
                ans = max(ans, ret - a);
            }
        }

        ans = max(ans, 0 - a); //아무것도 관측을 못했을 경우를 처리
    }

    std::cout << ans << endl;

}