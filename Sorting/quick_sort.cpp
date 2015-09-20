#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int st, int end)
{
	int pindex = st; // set partition index as start initially
	int pivot = a[end];
	for (int i = st; i < end; i++)
	{
		if (a[i] <= pivot)
		{
			swap(a[i], a[pindex]); // swap if element is lesser than pivot
			pindex++;
		}
	}
	swap(a[pindex], a[end]); // swap pivot with element at pindex
	return pindex;
}
void quicksort(int a[], int st, int end)
{
	if (st < end)
	{
		int p = partition(a, st, end);
		quicksort(a, st, p - 1);
		quicksort(a, p + 1, end);
	}

}
int main()
{
	//freopen("in.txt", "r", stdin);
	int n;  //size of array
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	quicksort(a, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	return 0;
}
