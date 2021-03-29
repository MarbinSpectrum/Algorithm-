#ifndef _GLIBCXX_NO_ASSERT 
#include <cassert> 
#endif #include <cctype>
#include <cerrno> 
#include <cfloat> 
#include <ciso646> 
#include <climits> 
#include <clocale> 
#include <cmath> 
#include <csetjmp> 
#include <csignal>
#include <cstdarg> 
#include <cstddef>
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 

#if __cplusplus >= 201103L 
#include <ccomplex> 
#include <cfenv> 
#include <cinttypes> 
#include <cstdalign> 
#include <cstdbool>
#include <cstdint> 
#include <ctgmath>
#include <cwchar> 
#include <cwctype>
#endif 
//
//// C++ 
#include <algorithm> 
#include <bitset> 
#include <complex> 
#include <deque> 
#include <exception> 
#include <fstream> 
#include <functional> 
#include <iomanip> 
#include <ios> 
#include <iosfwd> 
#include <iostream> 
#include <istream> 
#include <iterator> 
#include <limits> 
#include <list> 
#include <locale> 
#include <map> 
#include <memory> 
#include <new> 
#include <numeric>
#include <ostream> 
#include <queue> 
#include <set> 
#include <sstream> 
#include <stack> 
#include <stdexcept> 
#include <streambuf> 
#include <string> 
#include <typeinfo> 
#include <utility> 
#include <valarray> 
#include <vector> 
//
#if __cplusplus >= 201103L 
#include <array> 
#include <atomic> 
#include <chrono> 
#include <condition_variable> 
#include <forward_list> 
#include <future> 
#include <initializer_list> 
#include <mutex> 
#include <random> 
#include <ratio>
#include <regex> 
#include <scoped_allocator> 
#include <system_error> 
#include <thread> 
#include <tuple> 
#include <typeindex> 
#include <type_traits> 
#include <unordered_map> 
#include <unordered_set> 
#endif

#pragma warning(disable:4996)

using namespace std;


#define endl "\n"
#define int long long
#define float double
#define Debug(a,b) cout << a << " " << b << endl


int GCD(int a, int b)
{
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

int LCM(int a, int b)
{
    return a * b / GCD(a, b);
}

int Ceil(double n)
{
    if (n - (int)(n) > 0)
        return (int)n + 1;
    else
        return n;
}

int Pow(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    int temp = Pow(a, b / 2);

    return temp * temp * a * (b % 2);
}

const int INF = 8999999999999999999;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

#define �������а� 0
#define ����� 1
#define �̷��� 2
#define �žӰ� 3
#define ȯ�������� 4
#define ������ 5
#define �л�ȸ�� 6
#define �������а� 7

int D;

const int MOD = 1000000007;

vector<vector<int>> MUL(vector<vector<int>> A, vector<vector<int>> B)
{
    vector<vector<int>> temp(B[0].size(), vector<int>(A.size()));

    for(int i = 0; i < A.size(); i++)
        for (int j = 0; j < B[0].size(); j++)
            for (int k = 0; k < A[0].size(); k++)
            {
                temp[j][i] += (A[i][k] * B[k][j])%MOD;
                temp[j][i] %= MOD;
            }

    return temp;
}
vector<vector<int>> POW(vector<vector<int>> A, int n)
{
    if (n == 0)
    {
        vector<vector<int>> temp(A.size(), vector<int>(A.size()));
        for (int i = 0; i < temp.size(); i++)
            temp[i][i] = 1;
        return temp;
    }
    else if (n == 1)
        return A;
    else if (n % 2 == 0)
    {
        vector<vector<int>> temp = POW(A, n / 2);
        return MUL(temp,temp);
    }
    else
    {
        vector<vector<int>> temp = POW(A, n / 2);
        return MUL(MUL(temp, temp),A);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> M(8, vector<int>(8));

    M[�������а�][�����] = 1; M[�������а�][�̷���] = 1;
    M[�����][�������а�] = 1; M[�����][�̷���] = 1; M[�����][�žӰ�] = 1;
    M[�̷���][�����] = 1; M[�̷���][�������а�] = 1; M[�̷���][�žӰ�] = 1;  M[�̷���][ȯ��������] = 1;
    M[ȯ��������][�̷���] = 1; M[ȯ��������][�žӰ�] = 1; M[ȯ��������][������] = 1;  M[ȯ��������][�������а�] = 1;
    M[�žӰ�][�����] = 1; M[�žӰ�][�̷���] = 1; M[�žӰ�][ȯ��������] = 1;  M[�žӰ�][������] = 1;
    M[������][�žӰ�] = 1; M[������][ȯ��������] = 1; M[������][�л�ȸ��] = 1; 
    M[�������а�][ȯ��������] = 1; M[�������а�][�л�ȸ��] = 1;
    M[�л�ȸ��][�������а�] = 1; M[�л�ȸ��][������] = 1;

    vector<vector<int>> N(8, vector<int>(1));
    N[�������а�][0] = 1;

    cin >> D;

    D--;

    POW(M, D);
    
    vector<vector<int>> Result = MUL(POW(M, D), N);

    cout << (Result[0][�����] + Result[0][�̷���]) % MOD << endl;



}