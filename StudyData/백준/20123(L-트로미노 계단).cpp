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

// C++ 
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
#define Debug(a,b) cout << a << " " << b << endl
#define Init(a,b) memset(a,b,sizeof(a))

const int INF = 0x3fffffff;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

int N;

deque<deque<char>> Data[2];

void Print(int data)
{
    for (int i = 0; i < Data[data].size(); i++)
    {
        for (int j = 0; j < Data[data][i].size(); j++)
            //if (Data[data][i][j] == '|')
            //    cout << " │ ";
            //else if (Data[data][i][j] == '-')
            //    cout << " - ";
            //else if (Data[data][i][j] == 'b')
            //    cout << " └ ";
            //else if (Data[data][i][j] == 'd')
            //    cout << " ┘ ";
            //else if (Data[data][i][j] == 'p')
            //    cout << " ┌ ";
            //else if (Data[data][i][j] == 'q')
            //    cout << " ┐ ";
            cout << Data[data][i][j];
        //cout << endl;
        cout << endl;
    }
}

void AddCase1(int data)
{
    //cout << 1 << endl;
    for (int i = 0; i < 2; i++)
    {
        deque<char> temp;
        Data[data].push_front(temp);
    }

    int count = 0;
    for (int i = 0; i < Data[data].size() - 1;)
    {
        if (count % 2 == 0)
        {
            Data[data][i].push_back('|');
            Data[data][i + 1].push_back('b');   Data[data][i + 1].push_back('-');
            i += 2;
        }
        else
        {
            Data[data][i].push_back('-');  Data[data][i].push_back('q');
            Data[data][i + 1].push_back('|');
            i += 1;
        }
        count++;
    }
}

void AddCase2(int data)
{
    for (int i = 0; i < 2; i++)
    {
        deque<char> temp;
        Data[data].push_front(temp);
    }

    for (int i = 0; i < 2; i++)
    {
        deque<char> temp;
        Data[data].push_back(temp);
    }

    Data[data][0].push_front('|');
    Data[data][1].push_front('-'); Data[data][1].push_front('b');

    Data[data][Data[data].size() - 2].push_front('|');
    Data[data][Data[data].size() - 1].push_front('-'); Data[data][Data[data].size() - 1].push_front('b');

    for (int i = 2; i < Data[data].size() - 5; i += 3)
    {
        Data[data][i].push_front('-');  Data[data][i].push_front('p');
        Data[data][i + 1].push_front('|'); Data[data][i + 1].push_front('|');
        Data[data][i + 2].push_front('d'); Data[data][i + 2].push_front('-');
    }

    for (int i = 2; i < Data[data].size() - 5; i += 3)
    {
        Data[data][Data[data].size() - 2].push_front('|');  Data[data][Data[data].size() - 2].push_front('-');  Data[data][Data[data].size() - 2].push_front('p');
        Data[data][Data[data].size() - 1].push_front('d');  Data[data][Data[data].size() - 1].push_front('-'); Data[data][Data[data].size() - 1].push_front('|');
    }

    Data[data][Data[data].size() - 4].push_front('-'); Data[data][Data[data].size() - 4].push_front('p');
    Data[data][Data[data].size() - 3].push_front('|'); Data[data][Data[data].size() - 3].push_front('|');
    Data[data][Data[data].size() - 2].push_front('|'); Data[data][Data[data].size() - 2].push_front('-'); Data[data][Data[data].size() - 2].push_front('b'); Data[data][Data[data].size() - 2].push_front('|');
    Data[data][Data[data].size() - 1].push_front('d'); Data[data][Data[data].size() - 1].push_front('-'); Data[data][Data[data].size() - 1].push_front('-'); Data[data][Data[data].size() - 1].push_front('b');

    //Print(data);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < 6; i++)
    {
        deque<char> temp(i + 1);
        Data[0].push_back(temp);
    }

    Data[0][0][0] = '|';
    Data[0][1][0] = 'b';  Data[0][1][1] = '-';
    Data[0][2][0] = 'p';  Data[0][2][1] = '-'; Data[0][2][2] = '|';
    Data[0][3][0] = '|';  Data[0][3][1] = '|'; Data[0][3][2] = 'b'; Data[0][3][3] = '-';
    Data[0][4][0] = '|';  Data[0][4][1] = 'b'; Data[0][4][2] = '-'; Data[0][4][3] = '|'; Data[0][4][4] = '|';
    Data[0][5][0] = 'b';  Data[0][5][1] = '-'; Data[0][5][2] = '-'; Data[0][5][3] = 'd'; Data[0][5][4] = 'b'; Data[0][5][5] = '-';

    for (int i = 0; i < 9; i++)
    {
        deque<char> temp(i + 1);
        Data[1].push_back(temp);
    }

    Data[1][0][0] = '|';
    Data[1][1][0] = 'b';  Data[1][1][1] = '-';
    Data[1][2][0] = 'p';  Data[1][2][1] = '-'; Data[1][2][2] = '|';
    Data[1][3][0] = '|';  Data[1][3][1] = '|'; Data[1][3][2] = 'b'; Data[1][3][3] = '-';
    Data[1][4][0] = '-';  Data[1][4][1] = 'd'; Data[1][4][2] = '-'; Data[1][4][3] = 'q'; Data[1][4][4] = '|';
    Data[1][5][0] = 'p';  Data[1][5][1] = '-'; Data[1][5][2] = '|'; Data[1][5][3] = '|'; Data[1][5][4] = 'b'; Data[1][5][5] = '-';
    Data[1][6][0] = '|';  Data[1][6][1] = '-'; Data[1][6][2] = 'd'; Data[1][6][3] = 'p'; Data[1][6][4] = '-'; Data[1][6][5] = 'p'; Data[1][6][6] = '-';
    Data[1][7][0] = '|';  Data[1][7][1] = '-'; Data[1][7][2] = 'q'; Data[1][7][3] = '|'; Data[1][7][4] = '|'; Data[1][7][5] = '|'; Data[1][7][6] = '|';  Data[1][7][7] = '|';
    Data[1][8][0] = 'b';  Data[1][8][1] = '-'; Data[1][8][2] = '|'; Data[1][8][3] = '-'; Data[1][8][4] = 'd'; Data[1][8][5] = '-'; Data[1][8][6] = 'd';  Data[1][8][7] = 'b'; Data[1][8][8] = '-';

    deque<int> Order;

    if (N == 2)
    {
        cout << "|" << endl;
        cout << "b-" << endl;
    }
    else if (N / (N + 1) / 2 % 3 != 0)
    {
        cout << "impossible" << endl;
        return 0;
    }
    else
    {
        if (N % 2 == 0)
        {
            int A = N;
            while (A != 6)
            {
                if ((A - 6) % 3 == 0)
                {
                    Order.push_front(2);
                    A -= 4;
                }
                else if (A % 3 == 2)
                {
                    Order.push_front(1);
                    A -= 2;
                }
                else
                    break;
            }

            if (A != 6)
            {
                cout << "impossible" << endl;
                return 0;
            }
            else
            {
                //Print(0);
                for (int i = 0; i < Order.size(); i++)
                {
                    if (Order[i] == 1)
                        AddCase1(0);
                    else
                        AddCase2(0);

                    ///Print(0);
                }

                Print(0);

            }
        }
        else if (N > 6)
        {
            int A = N;
            while (A != 9)
            {
                if (A % 3 == 2)
                {
                    Order.push_front(1);
                    A -= 2;
                }
                else if ((A - 6) % 3 == 0)
                {
                    Order.push_front(2);
                    A -= 4;
                }
                else
                    break;
            }
            if (A != 9)
            {
                cout << "impossible" << endl;
                return 0;
            }
            else
            {
                //Print(1);
                for (int i = 0; i < Order.size(); i++)
                {
                    if (Order[i] == 1)
                        AddCase1(1);
                    else
                        AddCase2(1);

                    //Print(1);
                }

                Print(1);


            }


        }
        else
        {
            cout << "impossible" << endl;
        }
    }





    return 0;
}
