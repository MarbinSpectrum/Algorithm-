#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long
#define float double

using namespace std;

int T;
const int MOD = 1000000007;
int A[101];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    A[0] = A[1] = 1;
    for(int i = 2; i <= 100; i++)
	{
		A[i] = (A[i-1] + A[i-2])%MOD;
	}
  
    cin >> T;
  	while(T--)
	{
	 int a;
	  cin >> a;
	  cout << A[a] << endl;
	  
	}
}