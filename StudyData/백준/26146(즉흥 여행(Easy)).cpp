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

const int MAX = 200001;

int N, M;
bool Visit0[MAX];
bool Visit1[MAX];
vector<int> V0[MAX];
vector<int> V1[MAX];
int v0 = 0;
int v1 = 0;

void DFS_0(int n)
{
    Visit0[n] = true;
    v0++;
    for (int i = 0; i < V0[n].size(); i++)
    {
        int next = V0[n][i];
        if (Visit0[next])
            continue;
        DFS_0(next);
    }
}

void DFS_1(int n)
{
    Visit1[n] = true;
    v1++;
    for (int i = 0; i < V1[n].size(); i++)
    {
        int next = V1[n][i];
        if (Visit1[next])
            continue;
        DFS_1(next);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        V0[a].push_back(b);
        V1[b].push_back(a);
    }

    DFS_0(1);

    if (v0 != N)
    {
        std::cout << "No" << endl;
        return 0;
    }

    DFS_1(1);

    if (v1 != N)
    {
        std::cout << "No" << endl;
        return 0;
    }

    std::cout << "Yes" << endl;

}