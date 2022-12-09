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

int Len[601];
int Cnt[601];
int Arr[601];
int N, K;

int GetLen(int a)
{
    if (Len[a] != -1)
        return Len[a];
    int& ret = Len[a];
    ret = 1;
    for (int i = a + 1; i < N; i++)
        if (Arr[a] < Arr[i])
            ret = max(ret, GetLen(i) + 1);
    return ret;
}
int GetCnt(int a)
{
    if (Cnt[a] != -1)
        return Cnt[a];
    int& ret = Cnt[a];
    if (GetLen(a) == 1)
        return ret = 1;
    ret = 0;
    for (int i = a + 1; i < N; i++)
        if (Arr[a] < Arr[i] && GetLen(a) - 1 == GetLen(i))
            ret = min((int)100000000000, ret + GetCnt(i));
    return ret;
}

vector<pair<int, int>> List0;
vector<pair<int, int>> List1;
void Ans(int k)
{
    List0.clear();
    List0 = List1;

    sort(List0.begin(), List0.end());

    for (int i = 0; i < List0.size(); i++)
    {
        int cnt = GetCnt(List0[i].second);
        if (k > cnt)
        {
            k -= cnt;
        }
        else
        {
            cout << List0[i].first << " ";
            List1.clear();
            for (int j = List0[i].second + 1; j < N; j++)
                if (Arr[List0[i].second] < Arr[j] &&
                    GetLen(List0[i].second) - 1 == GetLen(j))
                    List1.push_back({ Arr[j],j });

            Ans(k);
            break;
        }
    }
}

void F()
{
    for (int i = 0; i < 501; i++)
    {
        Len[i] = -1;
        Cnt[i] = -1;
    }

    std::cin >> N >> K;
    for (int i = 0; i < N; i++)
        std::cin >> Arr[i];

    int maxLen = 0;
    for (int i = 0; i < N; i++)
        maxLen = max(maxLen, GetLen(i));

    std::cout << maxLen << endl;
    List1.clear();
    for (int i = 0; i < N; i++)
        if (GetLen(i) == maxLen)
            List1.push_back({ Arr[i],i });

    Ans(K);
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int C;
    std::cin >> C;
    while (C--)
        F();

}