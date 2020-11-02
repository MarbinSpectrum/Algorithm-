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

const int INF = 99999999999999999;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };
const int Prime[] =
{
	2 ,3 ,5 ,7 ,11 ,13 ,17, 19 ,23 ,29,
	31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
	73 ,79 ,83 ,89 ,97 ,101 ,103 ,107 ,109 ,113,
	127 ,131, 137, 139 ,149 ,151, 157 ,163 ,167 ,173,
	179 ,181, 191, 193, 197, 199, 211, 223 ,227 ,229,
	233 ,239 ,241 ,251 ,257 ,263 ,269 ,271 ,277 ,281,
	283 ,293 ,307 ,311 ,313 ,317 ,331 ,337 ,347 ,349,
	353 ,359 ,367 ,373 ,379 ,383 ,389 ,397 ,401 ,409,
	419 ,421 ,431 ,433 ,439 ,443 ,449 ,457 ,461 ,463,
	467 ,479 ,487 ,491 ,499 ,503 ,509 ,521 ,523 ,541
};

////////////////////////////////////////////////////////////////////////

int H, W;
int X, Y;
int boxN = 0;

//삼각형 넓이구하기공식
double Triangle(pair<double, double> A, pair<double, double> B, pair<double, double> C)
{
    return abs((A.first * B.second + B.first * C.second + C.first * A.second) - (B.first * A.second + C.first * B.second + A.first * C.second)) / 2;
}

//상자들의좌표
char box[100][100];

//빛의 좌표
pair<double, double> Light;
vector<pair<double, double>> p;
//방향//각도//
set<pair<double, double>> slopeSet;

void Search(int x, int y, pair<double, double> coord, pair<double, double> slope) {
    if (x == -1 || x == W || y == -1 || y == H || box[y][x] == '#') {
        // printf("[%lf %lf]\n", coord.first, coord.second);
        p.push_back(coord);
        return;
    }
    int nx, ny;
    int face_x, face_y;
    if (slope.first > 0) {
        nx = x + 1;
        face_x = x + 1;
    }
    else {
        nx = x - 1;
        face_x = x;
    }
    if ((slope.first) * (slope.second) > 0) {
        ny = y + 1;
        face_y = y + 1;
    }
    else {
        ny = y - 1;
        face_y = y;
    }
    double y_nx, x_ny;
    y_nx = coord.second + (slope.second) * (face_x - coord.first);
    x_ny = coord.first + ((face_y - coord.second) / (slope.second));
    if (y + 1e-7 < y_nx && y_nx < y + 1 - 1e-7 && (x_ny<x - 1e-7 || x_ny>x + 1 + 1e-7)) {
        coord.first = face_x;
        coord.second = y_nx;
        Search(nx, y, coord, slope);
    }
    else if (x + 1e-7 < x_ny && x_ny < x + 1 - 1e-7 && (y - 1e-7 > y_nx || y_nx > y + 1 + 1e-7)) {
        coord.first = x_ny;
        coord.second = face_y;
        Search(x, ny, coord, slope);
    }
    else {
        coord.first = face_x;
        coord.second = face_y;

        if (slope.second > 0 && (nx == -1 || nx == W || box[y][nx] == '#'))
        {
            // printf("[%lf %lf]\n", coord.first, coord.second);
            p.push_back(coord);
        }
        if (slope.second < 0 && (ny == -1 || ny == H || box[ny][x] == '#'))
        {
            //  printf("[%lf %lf]\n", coord.first, coord.second);
            p.push_back(coord);
        }
        Search(nx, ny, coord, slope);
        if (slope.second > 0 && (ny == -1 || ny == H || box[ny][x] == '#'))
        {
            // printf("[%lf %lf]\n", coord.first, coord.second);
            p.push_back(coord);
        }
        if (slope.second < 0 && (nx == -1 || nx == W || box[y][nx] == '#'))
        {
            // printf("[%lf %lf]\n", coord.first, coord.second);
            p.push_back(coord);
        }
    }
}

int32_t main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

    cin >> H >> W;

    for (int y = 0; y < H; y++)
    {
        for (int x = 0; x < W; x++)
        {
            cin >> box[y][x];
            if (box[y][x] == '*')
            {
                X = x;
                Y = y;
                Light = make_pair(x + 0.5, y + 0.5);
            }
            else if (box[y][x] == '#')
                boxN++;
        }
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            pair<double, double> sl;
            int x = W * j;
            int y = H * i;
            if ((x - Light.first) > 0)
                sl.first = 1;
            else
                sl.first = -1;
            sl.second = (y - Light.second) / (x - Light.first);
            slopeSet.insert(sl);
        }
    }

    for (int y = 0; y <= H; y++)
        for (int x = 0; x <= W; x++)
        {
            pair<double, double> sl;
            if ((x - Light.first) > 0)
                sl.first = 1;
            else
                sl.first = -1;

            sl.second = (y - Light.second) / (x - Light.first);

            if (slopeSet.find(sl) == slopeSet.end())
                slopeSet.insert(sl);
        }

    for (set<pair<double, double> >::iterator it = slopeSet.begin(); it != slopeSet.end(); it++)
        Search(X, Y, Light, *it);

    double Result = 0;
    for (int i = 0; i < p.size(); i++)
    {
        //  printf("[%lf %lf]\n", p[i].first, p[i].second);
        int j = (i + 1) % p.size();
        Result += Triangle(Light, p[i], p[j]);

    }

    printf("%.13lf", W * H - Result - boxN);

}
