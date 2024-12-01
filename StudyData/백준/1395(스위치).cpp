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

int N,M;
vector<int> Tree;
vector<int> Lazy;

void UpdateLazy(int node, int left, int right, int s, int t)
{
    if (Lazy[node] != 0)
    {
        if (Lazy[node] % 2 == 1)
        {
            int len = right - left + 1;
            Tree[node] = len - Tree[node];
        }

        if (left != right) 
        {
            Lazy[node * 2] += Lazy[node];
            Lazy[node * 2 + 1] += Lazy[node];
        }
        Lazy[node] = 0;
    }
}

void Update(int node, int left, int right, int s, int t)
{
    UpdateLazy(node, left, right, s, t);
    if (t < left || s > right)
        return;

    if (s <= left && right <= t)
    {
        int len = right - left + 1;
        Tree[node] = len - Tree[node];
        if (left != right) 
        {
            Lazy[node * 2] += 1;
            Lazy[node * 2 + 1] += 1;
        }
        return;
    }

    int mid = (left + right) / 2;
    Update(node * 2, left, mid, s, t);
    Update(node * 2 + 1, mid + 1, right, s, t);
    Tree[node] = Tree[node * 2] + Tree[node * 2 + 1];
}

int GetValue(int node, int left, int right, int s, int t)
{
    UpdateLazy(node, left, right, s, t);
    if (t < left || s > right)
        return 0;

    if (s <= left && right <= t)
        return Tree[node];

    int mid = (left + right) / 2;
    return GetValue(node * 2, left, mid, s, t) + GetValue(node * 2 + 1, mid + 1, right, s, t);
}



int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    std::cin >> N >> M;

    int H = ceil(log2f(N));
    Tree.resize(pow(2, H + 1));
    Lazy.resize(pow(2, H + 1));

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        if (a == 0)
            Update(1, 1, N, b, c);
        else
            std::cout << GetValue(1, 1, N, b, c) << endl;
    }
}
