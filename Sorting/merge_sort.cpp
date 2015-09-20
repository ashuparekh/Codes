#include<bits/stdc++.h>
using namespace std;

/*
Merge Sort
Time Complexity: O(n.log(n))
Auxilliary Space: O(n)
Can sort Linked List, Inversion count problem, Cant sort in place, is stable, used in external sorting
*/

void merge(int *a, int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = (r - m);
	int L[n1], R[n2];

	for (int i = 0; i < n1; i++)
		L[i] = a[l + i];

	for (int i = 0; i < n2; i++)
		R[i] = a[m + 1 + i];

	int i = 0, j = 0, k = l;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			k++;
			i++;
		}
		else
		{
			a[k] = R[j];
			k++;
			j++;
		}
	}
	while (i < n1)
	{
		a[k] = L[i];
		k++;
		i++;
	}
	while (j < n2)
	{
		a[k] = R[j];
		k++;
		j++;
	}

}
void mergeSort(int *a, int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2; // use l+(r-l)/2 to avoid overflow
		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	mergeSort(a, 0, n);

	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';

	return 0;
}
