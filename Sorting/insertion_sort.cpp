#include<bits/stdc++.h>
using namespace std;

/*
Insertion Sort
Time Complexity: O(n*n)
Auxilliary Space: O(1)
Can be used for small sized arrays (low overhead) and nearly sorted lists (adaptive method)
*/

void insertion_sort(int *a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int j = i;
		while (j > 0 && a[j - 1] > a[j])
		{
			swap(a[j - 1], a[j]);
			j--;
		}
	}
}
int main()
{
	freopen("in.txt", "r", stdin);
	int n; 								// total elements
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];                   // scan array

	insertion_sort(a, n);

	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';            // print sorted array

	return 0;
}
