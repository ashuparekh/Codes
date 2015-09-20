#include<bits/stdc++.h>
using namespace std;
// Returns minimum number of jumps to reach arr[h] from arr[l]
int dp[10000][10000];
int minJumps(int arr[], int l, int h)  // memoized solution
{
	// Base case: when source and destination are same
	if (h == l)
		return 0;

	// When nothing is reachable from the given source
	if (arr[l] == 0)
		return INT_MAX;

	if (dp[l][h] != 0)
		return dp[l][h];

	int min = INT_MAX;
	for (int i = l + 1; i <= h && i <= l + arr[l]; i++)
	{
		int jumps = minJumps(arr, i, h);
		if (jumps != INT_MAX && jumps + 1 < min)
			min = jumps + 1;
	}

	dp[l][h] = min;
	return min;
}
int minJumps2(int arr[], int l, int h)  // only recursive
{
	// Base case: when source and destination are same
	if (h == l)
		return 0;

	// When nothing is reachable from the given source
	if (arr[l] == 0)
		return INT_MAX;

	// Traverse through all the points reachable from arr[l]. Recursively
	// get the minimum number of jumps needed to reach arr[h] from these
	// reachable points.
	int min = INT_MAX;
	for (int i = l + 1; i <= h && i <= l + arr[l]; i++)
	{
		int jumps = minJumps2(arr, i, h);
		if (jumps != INT_MAX && jumps + 1 < min)
			min = jumps + 1;
	}

	return min;
}
int main()
{
	clock_t start = clock();
	freopen("in.txt", "r", stdin);

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << minJumps(a, 0, n - 1) << endl;

	clock_t end = clock();

	cout << (end - start) / (double) CLOCKS_PER_SEC;

	return 0;
}
