/*You are given a string s, consisting only of characters '0' and '1'.

You have to choose a contiguous substring of s and remove all occurrences of the character, which is a strict minority in it, from the substring.

That is, if the amount of '0's in the substring is strictly smaller than the amount of '1's, remove all occurrences of '0' from the substring. If the amount of '1's is strictly smaller than the amount of '0's, remove all occurrences of '1'. If the amounts are the same, do nothing.

You have to apply the operation exactly once. What is the maximum amount of characters that can be removed?*/

#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;
#define MOD 1000000007
#define int long long int
#define F first
#define S second
#define pb push_back
#define si set<int>
#define vi vector<int>
#define pii pair<int, int>
#define vpi vector<pii>
#define vpp vector<pair<int, pii>>
#define mii map<int, int>
#define mpi map<pii, int>
#define spi set<pii>
#define endl "\n"
#define sz(x) ((int)x.size())
#define all(p) p.begin(), p.end()
#define double long double
#define que_max priority_queue<int>
#define que_min priority_queue<int, vi, greater<int>>
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define print(a)          \
	for (auto x : a)      \
		cout << x << " "; \
	cout << endl
#define print1(a)    \
	for (auto x : a) \
	cout << x.F << " " << x.S << endl
#define print2(a, x, y)         \
	for (int i = x; i < y; i++) \
		cout << a[i] << " ";    \
	cout << endl
 
inline int power(int a, int b)
{
	int x = 1;
	while (b)
	{
		if (b & 1)
			x *= a;
		a *= a;
		b >>= 1;
	}
	return x;
}
inline int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
	const char *comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | ";
	__f(comma + 1, args...);
}
 
const int N = 200005;
int bs(int a[], int n, int j)
{
	int i = 0, k = n;
	while (i < k)
	{
		int mid = (i + k) / 2;
		if (a[mid] > j)
			k = mid - 1;
		else if (j < a[mid])
			i = mid + 1;
		else
			return mid;
	}
}
 
void solve()
{
	string s;
	cin>>s;
	int c=0,v=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='0')
		c++;
		if(s[i]=='1')
		v++;
	}
	if(c==0||v==0)
	cout<<"0"<<endl;
	else if(c==v)
	cout<<c-1<<endl; //we have take c-1 here because we have to perform the operation exactly 1 time
	else if(c<v)
	cout<<c<<endl;
	else
	cout<<v<<endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	clock_t z = clock();
 
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
 
	return 0;
}