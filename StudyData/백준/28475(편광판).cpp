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
int Arr[300000];
int CanMove[300000];
vector<int> tree;

void init(int node, int start, int end)
{
    if (start == end)
        tree[node] = CanMove[start];
    else
    {
        int mid = (start + end) / 2;
        init(node * 2, start, mid);
        init(node * 2 + 1, mid + 1, end);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }
}

int query(int node, int start, int end, int left, int right)
{
    if (right < start || end < left)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    return max(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}

void update(int node, int start, int end, int index, int value)
{
    if (start == end)
    {
        CanMove[index] = value;
        tree[node] = value;
    }
    else
    {
        int mid = (start + end) / 2;
        if (index <= mid)
            update(node * 2, start, mid, index, value);
        else
            update(node * 2 + 1, mid + 1, end, index, value);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }
}

void SetValue(int i, int v)
{
    Arr[i] = v;
    if (i - 1 >= 1)
    {
        int disValue = (Arr[i - 1] - Arr[i] + 8) % 8;
        if (disValue == 2 || disValue == 6)
            update(1, 1, N, i - 1, 1);
        else
            update(1, 1, N, i - 1, 0);
    }
    if (i + 1 <= N)
    {
        int disValue = (Arr[i + 1] - Arr[i] + 8) % 8;
        if (disValue == 2 || disValue == 6)
            update(1, 1, N, i, 1);
        else
            update(1, 1, N, i, 0);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    std::cin >> N >> M;
    int H = ceil(log2f(N));
    tree.resize(2 * (1 << H));

    for (int i = 1; i <= N; i++)
    {
        std::cin >> Arr[i];
        if (i - 1 >= 1)
        {
            int disValue = (Arr[i - 1] - Arr[i] + 8) % 8;
            if (disValue == 2 || disValue == 6)
                CanMove[i - 1] = 1;
        }
    }
    init(1, 1, N);

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        if (a == 1)
        {
            SetValue(b, c);
        }
        else if (a == 2)
        {
            int res = query(1, 1, N, b, c - 1);
            if (res > 0)
                std::cout << 0 << endl;
            else
                std::cout << 1 << endl;
        }
    }
}
