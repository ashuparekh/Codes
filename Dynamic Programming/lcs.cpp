#include <bits/stdc++.h>
using namespace std;
#define lld long long int

int lcs(string a, string b, int n, int m)
{
	if (m == 0 || n == 0)
		return 0;
	if (a[n - 1] == b[m - 1])
		return 1 + lcs(a, b, n - 1, m - 1);
	else
		return max(lcs(a, b, n - 1, m), lcs(a, b, n, m - 1));

}
string lcsa = "";
int dplcs(string a, string b, int m, int n)
{
	int l[m + 1][n + 1];

	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				l[i][j] = 0;
			else
			{
				if (a[i - 1] == b[j - 1])
					l[i][j] = l[i - 1][j - 1] + 1;

				else
					l[i][j] = max(l[i - 1][j], l[i][j - 1]);
			}
		}
	}

	//finds the string corresponding to lcs and stores in string lcsa in reverse form:

	int i = m, j = n;
	while (i > 0 && j > 0)
	{
		// If current character in a[] and b[] are same, then current character is part of LCS

		if (a[i - 1] == b[j - 1])
		{
			lcsa += a[i - 1]; // Put current character in result
			i--;
			j--;     // reduce values of i, j
		}

		// If not same, then find the larger of two and
		// go in the direction of larger value
		else if (l[i - 1][j] > l[i][j - 1])
			i--;
		else
			j--;
	}


	return l[m][n]; // returns length of lcs

}

int main()
{
	freopen("in.txt", "r", stdin);
	string a, b, lcstr = "";
	cin >> a >> b;
	int m = a.length();
	int n = b.length();
	int ans = 0;
	ans = dplcs(a, b, m, n);
	cout << ans << endl; // length of lcs prints
	cout << lcsa << endl; // prints lcsa in reverse form

	for (int i = lcsa.length() - 1; i >= 0; i--)
	{
		lcstr += lcsa[i]; // reverses string
	}
	cout << lcstr << endl;

	return 0;
}
