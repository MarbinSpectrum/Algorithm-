#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include <string.h>
#include <set>

#pragma warning(disable:4996)

using namespace std;

typedef long long ll;

ll const INF = 999999999999999999;
int const Dic[4][2] = { {0,+1},{0,-1},{+1,0},{-1,0} };
int L;
int B1_power;
int B2_power, B2_ammo;
int B3_power, B3_ammo, B3_length;
int zombie[20];
bool survive = false;

void DFS(int turn, int b2_ammo, int b3_ammo)
{
    if (zombie[turn] > 0)
        return;
    if (turn == L)
    {
        survive = true;
        return;
    }

    int idx = -1;
    for (int i = turn + 1; i < 20; i++)
        if (zombie[i] > 0)
        {
            idx = i;
            break;
        }

    if (idx == -1)
    {
        survive = true;
        return;
    }

    int hp = zombie[idx];
    int distance = abs(turn - idx);

    if (distance * B1_power < hp)
    {
        if (b2_ammo > 0)
        {
            zombie[idx] -= B2_power;
            DFS(turn + 1, b2_ammo - 1, b3_ammo);
            zombie[idx] += B2_power;
        }
        else
        {
            zombie[idx] -= B1_power;
            DFS(turn + 1, b2_ammo, b3_ammo);
            zombie[idx] += B1_power;
        }
    }
    else
    {
        if (b2_ammo > 0)
        {
            zombie[idx] -= B2_power;
            DFS(turn + 1, b2_ammo - 1, b3_ammo);
            zombie[idx] += B2_power;
        }

        zombie[idx] -= B1_power;
        DFS(turn + 1, b2_ammo, b3_ammo);
        zombie[idx] += B1_power;

    }

    if (b3_ammo > 0)
    {
        int b3_distance = min(19, idx + B3_length - 1);
        for (int i = idx; i <= b3_distance; i++)
            zombie[i] -= B3_power;
        DFS(turn + 1, b2_ammo, b3_ammo - 1);
        for (int i = idx; i <= b3_distance; i++)
            zombie[i] += B3_power;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> L;
    cin >> B1_power;
    cin >> B2_power >> B2_ammo;
    cin >> B3_power >> B3_length >> B3_ammo;

    memset(zombie, 0, sizeof(zombie));
    for (int i = 1; i <= L; i++)
        cin >> zombie[i];

    DFS(0, B2_ammo, B3_ammo);

    if (survive)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;


}