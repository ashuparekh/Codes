#include <bits/stdc++.h>
using namespace std;
#define lld long long int
int main()
{
	freopen("in.txt", "r", stdin);
	int n,ans=0;
	cin >> n;
	int a[n];
	int lis[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		lis[i] = 1;
	}

	for (int i = n - 1; i >= 0; i--)
	{
		int tmp = 0;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] > a[i])
			{
				tmp = max(tmp, lis[j]);
			}
		}
		lis[i] += tmp;
	}
//	for (int i = 0; i < n; i++)
	//cout << lis[i] << " ";
	sort(lis, lis + n);
	ans = lis[n - 1];
	cout << ans << endl;
	return 0;
}