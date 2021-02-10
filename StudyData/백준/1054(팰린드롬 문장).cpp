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
#define float double
#define Debug(a,b) cout << a << " " << b << endl
#define Init(a,b) memset(a,b,sizeof(a))

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	else
		return GCD(b, a % b);
}

int Ceil(double n)
{
	if (n - (int)(n) > 0)
		return (int)n + 1;
	else
		return n;
}

const int INF = 8999999999999999999;
const int Dic[4][2] = { {+1,+0},{-1,+0},{0,+1},{0,-1} };

////////////////////////////////////////////////////////////////////////

using namespace std;

set<string> ResultString;
int N;
string s[14];
bool hasFront(int n, string ss)
{
	if (s[n].length() >= ss.length())
	{
		for (int i = 0; i < ss.length(); i++)
			if (s[n][i] != ss[i])
				return false;
		return true;
	}
	return false;
}
bool hasBack(int n, string ss)
{
	if (s[n].length() >= ss.length())
	{
		for (int i = s[n].length() - ss.length(); i < s[n].length(); i++)
			if (s[n][i] != ss[i - (s[n].length() - ss.length())])
				return false;
		return true;
	}
	return false;
}
vector<int> CheckList[1 << 14];
map<tuple<string, int, int>, int> DP;
bool isPalindrome(string s, int a, int b)
{
	if (a >= b)
		return true;
	if (s[a] == s[b])
		return isPalindrome(s, a + 1, b - 1);
	else
		return false;
}
//s를 가진 문자열 
int D(string checkString,int bit,int flag)
{
	if (DP.find({ checkString,bit,flag }) != DP.end())
		return DP[{checkString, bit, flag}];

	string resS = checkString;

	int Res = 0;

	int bitCount = 0;
	int lastBit = 0;
	for (int i = 0; i < N; i++)
		if (bit & (1 << i))
		{
			bitCount++;
			lastBit = i;
		}

	if (bitCount == 1)
	{
		if (checkString.compare("NONE") == 0)
		{
			if (isPalindrome(s[lastBit], 0, s[lastBit].length() - 1))
				return DP[{resS, bit, flag}] = 1;
			else
				return DP[{resS, bit, flag}] = 0;
		}

		if (s[lastBit].length() < checkString.length())
		{
			if (flag == 1)
			{
				for (int i = 0; i < s[lastBit].length(); i++)
					if (checkString[i] != s[lastBit][s[lastBit].length() - 1 - i])
						return DP[{resS, bit, flag}] = 0;
				string temp = checkString.substr(s[lastBit].length(), checkString.length() - s[lastBit].length());

				if (isPalindrome(temp, 0, temp.length() - 1))
					return DP[{resS, bit, flag}] = 1;
			}
			else if (flag == 0)
			{
				for (int i = 0; i < s[lastBit].length(); i++)
					if (checkString[checkString.length() - 1 - i] != s[lastBit][i])
						return DP[{resS, bit, flag}] = 0;
				string temp = checkString.substr(0, checkString.length() - s[lastBit].length());

				if (isPalindrome(temp, 0, temp.length() - 1))
					return DP[{resS, bit, flag}] = 1;
			}
		}
		else 
		{
			if (flag == 1)
			{
				reverse(checkString.begin(), checkString.end());
				if (hasBack(lastBit, checkString))
				{
					if(s[lastBit].length() - checkString.length() == 0)
						return DP[{resS, bit, flag}] = 1;
					string temp = s[lastBit].substr(0, s[lastBit].length() - checkString.length());
	
					if (isPalindrome(temp, 0, temp.length() - 1))
						return DP[{resS, bit, flag}] = 1;
				}
			}
			else if (flag == 0)
			{
				reverse(checkString.begin(), checkString.end());
				if (hasFront(lastBit, checkString))
				{
					if (s[lastBit].length() - checkString.length() == 0)
						return DP[{resS, bit, flag}] = 1;
					string temp = s[lastBit].substr(checkString.length(), s[lastBit].length() - checkString.length());

					if (isPalindrome(temp, 0, temp.length() - 1))
						return DP[{resS, bit, flag}] = 1;
				}
			}
		}
		return DP[{resS, bit, flag}] = 0;
	}

	//앞에추가
	if (flag == 0)
	{
		if (checkString.compare("NONE") != 0)
		{
			for (int i = 1; i <= checkString.length(); i++)
			{
				string ch = checkString.substr(checkString.length() - i, i);
				reverse(ch.begin(), ch.end());
				if (i == checkString.length())
				{
					for (int j = 0; j < N; j++)
						if (bit & (1 << j))
							if (hasFront(j, ch))
							{
								if (s[j].length() != ch.length())
									Res += D(s[j].substr(ch.length(), s[j].length() - ch.length()), bit - (1 << j), 1);
								else
									Res += D("NONE", bit - (1 << j), 1);
							}
				}
				else
				{

					for (int j = 0; j < N; j++)
						if (bit & (1 << j))
							if (s[j].compare(ch) == 0)
								Res += D(checkString.substr(0, checkString.length() - ch.length()), bit - (1 << j), 0);
				}
			}
		}
		else
		{
			for (int j = 0; j < N; j++)
				if (bit & (1 << j))
				{
					int  addN = D(s[j], bit - (1 << j), 1);
					Res += addN;
				}
		}
	}
	//뒤에 s를 포함한 문자열을 추가
	else
	{
		if (checkString.compare("NONE") != 0)
		{
			for (int i = 1; i <= checkString.length(); i++)
			{
				string ch = checkString.substr(0, i);
				reverse(ch.begin(), ch.end());
				if (i == checkString.length())
				{
					for (int j = 0; j < N; j++)
						if (bit & (1 << j))
							if (hasBack(j, ch))
							{
								if (s[j].length() != ch.length())
									Res += D(s[j].substr(0, s[j].length() - ch.length()), bit - (1 << j), 0);
								else
									Res += D("NONE", bit - (1 << j), 0);
							}
				}
				else
				{
					for (int j = 0; j < N; j++)
						if (bit & (1 << j))
							if (s[j].compare(ch) == 0)
								Res += D(checkString.substr(ch.length(), checkString.length() - ch.length()), bit - (1 << j), 1);
				}
			}
		}
		else
		{
			for (int j = 0; j < N; j++)
				if (bit & (1 << j))
				{				
						int  addN = D(s[j], bit - (1 << j), 0);
						Res += addN;
				}
		}
	}

	return DP[{resS, bit, flag}] = Res;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> s[i];

	int result = 0;

	for (int bit = 1; bit < (1 << N); bit++)
		result += D("NONE", bit, 0);

	cout << result << endl;




}