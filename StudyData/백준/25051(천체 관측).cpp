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
    //l�� r������ ����
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

        //�� ������ ������ ��ó��
        float angle = (float)(180.0 / (atan(1) * 4) * atan2(y, x));
        angle = fmod(angle + 360.0, 360.0);
        Star.emplace_back(angle, x * x + y * y, s);
    }

    //������ ���������� ����
    sort(Star.begin(), Star.end());

    //�ڿ� �Ȱ��� ������ ��������ش�.
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
                //������ 90���� �Ѱ��.
                //l�� ������Ų��.
                float lDis = get<1>(Star[l]);
                float lValue = get<2>(Star[l]);
                if (a >= lDis)
                {
                    //������ �����ߴ� ���̴�.
                    //������ �������ش�.
                    ret -= lValue;
                    ans = max(ans, ret - a);
                }
                l++;
            }

            //������������� ������ 90�� �����̴�.
            float rDis = get<1>(Star[r]);
            float rValue = get<2>(Star[r]);
            if (a >= rDis)
            {
                //���Խ�ų�� �ִ� ���̴�.
                //������ ������ ���Խ����ش�.
                ret += rValue;
                ans = max(ans, ret - a);
            }
        }

        ans = max(ans, 0 - a); //�ƹ��͵� ������ ������ ��츦 ó��
    }

    std::cout << ans << endl;

}