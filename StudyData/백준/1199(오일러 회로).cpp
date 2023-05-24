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

int N;
struct Edge
{
    int next;
    int degree;
    Edge* reverse;
};

vector<Edge*> V[1002];
vector<int> ans;
bool Check()
{
    for (int i = 0; i < N; i++)
    {
        int cnt = 0;
        for (int j = 0; j < V[i].size(); j++)
            cnt += V[i][j]->degree;
        if (cnt % 2)
            return false;
    }
    return true;
}

void DFS(int now)
{
    while(V[now].empty() == false)
    {
        Edge* edge = V[now].back();
        if(edge->degree == 0)
            V[now].pop_back();

        if(edge->degree > 0)
        {
            edge->degree--;
            edge->reverse->degree--;
            DFS(edge->next);
        }
    }

    ans.push_back(now);
}
int MAP[1002][1002];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> MAP[i][j];
            if (MAP[i][j] > 0 && MAP[j][i] == 0)
            {
                Edge* E0 = new Edge;
                E0->next = j;
                Edge* E1 = new Edge;
                E1->next = i;
                E0->reverse = E1;
                E1->reverse = E0;
                E0->degree = MAP[i][j];
                E1->degree = MAP[i][j];
                V[i].push_back(E0);
                V[j].push_back(E1);
            }

        }
    }

    if (Check() == false)
    {
        std::cout << -1 << endl;
        return 0;
    }

    DFS(0);

    for (int i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i] + 1 << " ";
    }

    std::cout << endl;
}