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

int N;
vector<string> Arr;
int OverLapLen[16][16];

bool IncludeStr(string findStr, string mainStr)
{
    for (int i = 0; i < (mainStr.length() - findStr.length() + 1); i++)
    {
        bool flag = true;
        for (int j = 0; j < findStr.length(); j++)
        {
            int idx = i + j;
            if (mainStr[idx] != findStr[j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            return true;
        }
    }
    return false;
}

int GetOverLapSize(string leftStr, string rightStr)
{
    int res = 0;
    int minLen = min(leftStr.length(), rightStr.length());
    for (int i = 1; i < minLen; i++)
    {
        bool flag = true;
        int leftIdx = leftStr.length() - i;
        int rightIdx = 0;
        for (int j = 0; j < i; j++)
        {
            if (leftStr[leftIdx] == rightStr[rightIdx])
            {
                leftIdx++;
                rightIdx++;
            }
            else
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            res = max(res, i);
        }
    }

    return res;
}

int DP[1 << 16][16];
int NextStr[16];
int Dp(int bit,int tailIdx)
{
    int& ret = DP[bit][tailIdx];
    if (ret != -1)
    {
        return ret;
    }

    bool flag = true;
    ret = INF;
    for (int i = 0; i < N; i++)
    {
        if ((bit & (1 << i)) > 0)
            continue;
        flag = false;
        int addLen = Arr[i].length() - OverLapLen[tailIdx][i];
        int next = Dp((bit | (1 << i)), i) + addLen;
        if (ret > next)
        {
            ret = next;
            NextStr[tailIdx] = i;
        }
    }
    if (flag)
    {
        ret = 0;
    }
    return ret;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int C;
    std::cin >> C;
    while (C--)
    {
        Arr.clear();
        for (int i = 0; i < 16; i++)
            for (int j = 0; j < 16; j++)
                OverLapLen[i][j] = -1;

        for (int i = 0; i < (1 << 16); i++)
            for (int j = 0; j < 16; j++)
                for (int k = 0; k < 16; k++)
                    DP[i][j] = -1;

        for (int i = 0; i < 16; i++)
                NextStr[i] = -1;

        int tempN;
        std::cin >> tempN;
        vector<string> tempArr;
        for (int i = 0; i < tempN; i++)
        {
            string str;
            std::cin >> str;
            tempArr.push_back(str);
        }

        sort(tempArr.begin(), tempArr.end(), [](string a, string b) 
            { 
                if (a.length() > b.length()) 
                {
                    return true;
                }
                else 
                {
                    return false;
                }
            });

        for (int i = 0; i < tempN; i++)
        {
            string str = tempArr[i];
            bool flag = true;
            for (int j = 0; j < Arr.size(); j++)
            {
                if (IncludeStr(str, Arr[j]))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                Arr.push_back(str);
            }
        }
        N = Arr.size();

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                OverLapLen[i][j] = GetOverLapSize(Arr[i], Arr[j]);

        string ans = "";
        int resultSize = INF;
        for (int i = 0; i < N; i++)
        {
            for (int i = 0; i < (1 << 16); i++)
                for (int j = 0; j < 16; j++)
                    for (int k = 0; k < 16; k++)
                        DP[i][j] = -1;

            for (int i = 0; i < 16; i++)
                NextStr[i] = -1;

            int res = Dp((1 << i), i) + Arr[i].length();
            if (resultSize > res)
            {
                resultSize = res;
                string resStr = Arr[i];

                int idx = i;
                for (int j = 0; j < N-1; j++)
                {
                    int f = idx;
                    int e = NextStr[idx];
                    for (int j = OverLapLen[f][e]; j < Arr[e].length(); j++)
                        resStr += Arr[e][j];
                    idx = e;
                }

                ans = resStr;
            }
        }

        std::cout << ans << endl;
    }
    
}