#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int lpal(string s, int a, int n)
{

	if (a == n)
		return 1;
	if (s[a] == s[n] && a == n - 1)
		return 2;

	if (dp[a][n] != 0)
		return dp[a][n];

	if (s[a] == s[n])
	{
		dp[a][n] = lpal(s, a + 1, n - 1) + 2;
		return dp[a][n];
	}

	if (s[a] != s[n])
	{
		dp[a][n] = max(lpal(s, a + 1, n), lpal(s, a, n - 1));
		return dp[a][n];
	}

}
int main()
{
	freopen("in.txt", "r", stdin);
	string s;
	getline(cin, s);
	cout << lpal(s, 0, s.length() - 1) << endl;
	return 0;
}
