#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<map>

#pragma warning(disable:4996)

using namespace std;

string Add(string s)
{
    vector<int> A(s.length());
    vector<int> B(s.length());

    for (int i = 0; i < s.length(); i++)
        B[i] = s[i] - '0';

    B[s.length() - 1]++;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (i != s.length() - 1)
            B[i] += A[i + 1];

        if (B[i] >= 2)
        {
            B[i] -= 2;
            A[i]++;
        }
    }
    string temp;

    for (int i = 0; i < B.size(); i++)
        temp += to_string(B[i]);

    return temp;
}

bool Check(string s)
{

    for (int i = 0; i < s.length(); i++)
        if (s[i] == '0')
            return false;

    return true;
}

int N;
vector<int> Arr;
vector<int> Order;
vector<queue<string>> Number;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Number.resize(1001);
    cin >> N;
    Arr.resize(N);
    Order.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> Arr[i];
        Order[i] = Arr[i];
    }

    sort(Arr.begin(), Arr.end());

    string emp = "";
    for (int i = 0; i < Arr[0]; i++)
        emp += "0";

    Number[Arr[0]].push(emp);

    for (int i = 1; i < Arr.size(); i++)
    {
        if (Check(emp))
        {
            cout << -1 << "\n";
            return 0;
        }

        emp = Add(emp);

        while (emp.length() < Arr[i])
            emp += "0";
        Number[Arr[i]].push(emp);
    }
    cout << 1 << "\n";
    for (int i = 0; i < Order.size(); i++)
    {
        cout << Number[Order[i]].front() << "\n";
        Number[Order[i]].pop();
    }

    return 0;

}