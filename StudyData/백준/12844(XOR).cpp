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

void UpdateLazy(int node, int left, int right)
{
    if (Lazy[node] != 0)
    {
        int len = right - left + 1;
        Tree[node] = Tree[node] ^ Lazy[node] * (len % 2);

        if (left != right) 
        {
            Lazy[node * 2] ^= Lazy[node];
            Lazy[node * 2 + 1] ^= Lazy[node];
        }
        Lazy[node] = 0;
    }
}

void Update(int node, int left, int right, int s, int t, int k)
{
    UpdateLazy(node, left, right);
    if (t < left || s > right)
        return;

    if (s <= left && right <= t)
    {
        Lazy[node] ^= k;
        UpdateLazy(node, left, right);
        return;
    }

    int mid = (left + right) / 2;
    Update(node * 2, left, mid, s, t, k);
    Update(node * 2 + 1, mid + 1, right, s, t, k);
    Tree[node] = Tree[node * 2] ^ Tree[node * 2 + 1];
}

int GetValue(int node, int left, int right, int s, int t)
{
    UpdateLazy(node, left, right);
    if (t < left || s > right)
        return 0;

    if (s <= left && right <= t)
        return Tree[node];

    int mid = (left + right) / 2;
    return GetValue(node * 2, left, mid, s, t) ^ GetValue(node * 2 + 1, mid + 1, right, s, t);
}

void PrintArr()
{
    return;
    for (int i = 1; i <= N; i++)
        std::cout << GetValue(1, 1, N, i, i) << " ";
    std::cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    std::cin >> N;
    int H = ceil(log2f(N));
    Tree.resize(pow(2, H + 1));
    Lazy.resize(pow(2, H + 1));

    for (int i = 1; i <= N; i++)
    {
        int a;
        std::cin >> a;
        Update(1, 1, N, i, i, a);
    }

    PrintArr();
    std::cin >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, c,d;
        std::cin >> a;
        if (a == 1)
        {
            std::cin >> b >> c >> d;   
            b++;
            c++;
            Update(1, 1, N, b, c, d);
            PrintArr();
        }
        else
        {
            std::cin >> b >> c;
            b++;
            c++;
            std::cout << GetValue(1, 1, N, b, c) << endl;
        }
    }
}
