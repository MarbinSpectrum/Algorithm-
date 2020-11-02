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

int T = 0;

int sr = 0;
int sc = 0;
int phm = 20;
int ph = 20; //플레이어 체력
int pw = 2; //플레이어 공격력
int pa = 2; //플레이어 방어력
int pe = 0; //플레이어 경험치
int pl = 1; //플레이어 레벨
int pwe = 0; //플레이어 무기
int par = 0; //플레이어 방어구
string po[4] = { "","","","" }; //플레이어 장신구
bool HasPO(string pon)
{
	for (int i = 0; i < 4; i++)
		if (po[i].compare(pon) == 0)
			return true;
	return false;
}
int CheckPO(string pon)
{
	if (HasPO(pon))
		return -1;
	for (int i = 0; i < 4; i++)
		if (po[i].compare("") == 0)
			return i;
	return -1;
}
int pr = -1;
int pc = -1;
string order;
string endMessage = "Press any key to continue.";
bool endGame = false;
int N, M;
char Field[100][100];
char Get(int r, int c)
{
	if (r < 0 || r >= N || c < 0 || c >= M)
		return '#';
	return Field[r][c];
}

int k = 0;
class Monster
{
public:
	string s; //이름
	int w; //공격력
	int a; //방어력
	int h; //최대체력
	int e; //몬스터경험치
	Monster(string as, int aw, int aa, int ah, int ae)
	{
		s = as;
		w = aw;
		a = aa;
		h = ah;
		e = ae;
	}
	Monster()
	{

	}

};
Monster MonsterData[100][100];
bool Boss = false;
int l = 0;
class Box
{
public:
	char t; //종류
	string s; //스텟
	Box(char at, string as)
	{
		t = at;
		s = as;
	}
	Box()
	{

	}
};
Box BoxData[100][100];

void Print()
{
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			if (pr == r && pc == c)
				printf("@");
			else
				printf("%c", Field[r][c]);
		}
		printf("\n");
	}
	if (ph < 0)
		ph = 0;
	printf("Passed Turns : %d\n", T);
	printf("LV : %d\n", pl);
	printf("HP : %d/%d\n", ph, phm);
	printf("ATT : %d+%d\n", pw, pwe);
	printf("DEF : %d+%d\n", pa, par);
	printf("EXP : %d/%d\n", pe, pl * 5);
	cout << endMessage << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;
    for (int r = 0; r < N; r++)
    {
        string temp;
        cin >> temp;
        for (int c = 0; c < M; c++)
        {
            Field[r][c] = temp[c];
            switch (temp[c])
            {
            case '@':
                Field[r][c] = '.';
                sr = r;
                sc = c;
                pr = r;
                pc = c;
                break;
            case '&':
            case 'M':
                k++;
                break;
            case 'B':
                l++;
                break;
            }
        }
    }
    cin >> order;
    int r, c;
    while (k--)
    {
        string ts;
        int tw, ta, th, te;
        cin >> r >> c >> ts >> tw >> ta >> th >> te;
        MonsterData[r - 1][c - 1] = Monster(ts, tw, ta, th, te);
    }
    while (l--)
    {
        char tt;
        string ts;
        cin >> r >> c >> tt >> ts;
        BoxData[r - 1][c - 1] = Box(tt, ts);
    }

    while (T < order.length())
    {
        //Print();
        int nr = pr;
        int nc = pc;
        switch (order[T])
        {
        case 'R':
            nc++;
            break;
        case 'L':
            nc--;
            break;
        case 'U':
            nr--;
            break;
        case 'D':
            nr++;
            break;
        }
        switch (Get(nr, nc))
        {
        case '.':
        case '^':
            pr = nr;
            pc = nc;
            break;
        case '#':
            break;
        case 'B':
            pr = nr;
            pc = nc;
            Field[nr][nc] = '.';
            switch (BoxData[nr][nc].t)
            {
            case 'W':
                pwe = stoi(BoxData[nr][nc].s);
                break;
            case 'A':
                par = stoi(BoxData[nr][nc].s);
                break;
            case 'O':
                int POpos = CheckPO(BoxData[nr][nc].s);
                if (POpos != -1)
                    po[POpos] = BoxData[nr][nc].s;
                break;
            }
            break;
        case 'M':
            Boss = true;
        case '&':
            int bt = 0;
            int mh = MonsterData[nr][nc].h;

            if (Boss && HasPO("HU"))
                ph = phm;

            while (true)
            {
                int attack = pw + pwe;
                if (bt == 0 && HasPO("CO"))
                    if (HasPO("DX"))
                        attack *= 3;
                    else
                        attack *= 2;
                mh -= max(1, attack - MonsterData[nr][nc].a);
                // printf("M:%d\n",mh);
                if (mh <= 0)
                    break;

                if (Boss && HasPO("HU") && bt == 0)
                {
                }
                else
                {
                    int armor = pa + par;
                    ph -= max(1, MonsterData[nr][nc].w - armor);
                    // printf("p:%d\n",ph);
                }
                if (ph <= 0)
                    break;
                bt++;
            }

            if (mh <= 0)
            {
                pr = nr;
                pc = nc;
                Field[nr][nc] = '.';
                pe += HasPO("EX") ? (int)(1.2f * MonsterData[nr][nc].e) :
                    MonsterData[nr][nc].e;
                if (pe >= pl * 5)
                {
                    pe = 0;
                    pl++;
                    phm += 5;
                    pw += 2;
                    pa += 2;
                    ph = phm;
                }
                if (HasPO("HR"))
                    ph += 3;
                if (ph > phm)
                    ph = phm;
                if (Boss)
                {
                    endMessage = "YOU WIN!";
                    T++;
                    endGame = true;
                }
            }

            if (ph <= 0)
            {
                Boss = false;
                if (HasPO("RE"))
                {
                    for (int i = 0; i < 4; i++)
                        if (po[i].compare("RE") == 0)
                            po[i] = "";
                    ph = phm;
                    pr = sr;
                    pc = sc;
                }
                else
                {
                    pr = -1;
                    pc = -1;
                    endMessage = "YOU HAVE BEEN KILLED BY ";
                    endMessage += MonsterData[nr][nc].s;
                    endMessage += "..";
                    T++;
                    endGame = true;
                }
            }
            break;
        }

        if (endGame)
            break;

        if (Get(pr, pc) == '^')
        {
            ph -= HasPO("DX") ? 1 : 5;
            if (ph <= 0)
            {
                Boss = false;
                if (HasPO("RE"))
                {
                    for (int i = 0; i < 4; i++)
                        if (po[i].compare("RE") == 0)
                            po[i] = "";
                    ph = phm;
                    pr = sr;
                    pc = sc;
                }
                else
                {
                    pr = -1;
                    pc = -1;
                    endGame = true;
                    endMessage = "YOU HAVE BEEN KILLED BY SPIKE TRAP..";
                    T++;
                    endGame = true;
                    break;
                }
            }
        }
        T++;

    }

    Print();
}