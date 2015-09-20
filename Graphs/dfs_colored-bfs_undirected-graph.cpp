#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> v[100002];

bool visited2[100002];
void dfs(int s)
{

	visited2[s] = true;
	cout << s << " ";

	int i;
	for (i = 0; i < v[s].size(); i++)
	{
		if (visited2[v[s][i]] == 0)
			dfs(v[s][i]);
	}
}

void bfs(int s)
{
	bool visited[100002];
	queue<int> q;
	q.push(s);
	while (!q.empty())
	{
		int curr = q.front();
		cout << curr << " ";
		visited[curr] = true;
		q.pop();
		for (int i = 0; i < v[curr].size(); i++)
		{
			if (!visited[v[curr][i]])
			{
				q.push(v[curr][i]);
				visited[v[curr][i]] = true;
			}
		}
	}
}
void colored_bfs(int s, int d)
{
	int color[100002]; // 0->white, 1->gray, 2->black
	int dist[100002]; //initialize to infinity
	int pi[100002];  //predecessor vertex
	queue<int> q;
	q.push(s);
	while (!q.empty())
	{
		int curr = q.front();
		cout << curr << " ";
		color[curr] = true;
		q.pop();
		for (int i = 0; i < v[curr].size(); i++)
		{
			if (color[v[curr][i]] == 0)
			{
				q.push(v[curr][i]);
				color[v[curr][i]] = 1;
				dist[v[curr][i]] = dist[curr] + 1;
				pi[v[curr][i]] = curr;
			}
		}
		color[curr] = 2;
	}
	cout <<  dist[d]  <<  endl ; // outputs shortest path from  s --> d
}
int main()
{

	freopen("in.txt", "r", stdin);

	int nodes, edges;
	cin >> nodes >> edges;

	for (int i = 0; i < edges; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		v[n1].push_back(n2);
		v[n2].push_back(n1); //undirected graph
	}

	colored_bfs(2, 4);
	cout << endl;
	dfs(0);
	return 0;
}
