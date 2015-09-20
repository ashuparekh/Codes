#include <bits/stdc++.h>
#define lld long long int
#define pp pair<int,int>
using namespace std;

vector< pp > AdjList[100002]; // adj list for graph, max nodes 100002

int dijkstra(int s, int d, int node)
{
	int a, b, w;
	priority_queue<pp, vector<pp>,greater<pp> > Q;
	int dis[node];
	for (int i = 0; i < node; i++)
	{
		dis[i] = INT_MAX;
	}
	dis[s] = 0;
	Q.push(pp(s,dis[s]));
	while (!Q.empty())
	{
		a = Q.top().first;
		Q.pop();
		int size = AdjList[a].size();
		for (int i = 0; i < size; i++)
		{
			b = AdjList[a][i].first;
			w = AdjList[a][i].second;
			if (dis[b] > dis[a] + w)
			{
				dis[b] = dis[a] + w;
				Q.push(pp(b,dis[b]));
			}
		}

	}
	if (dis[d] == INT_MAX)
		return -1;
	else
		return dis[d];

}

int main()
{
	ios_base::sync_with_stdio(0);
	freopen("in.txt", "r", stdin);

	int nodes, edges, s, d; // 0 based nodes
	cin >> nodes >> edges;
	for (int i = 0; i < 100002; i++)
		AdjList[i].clear();

	for (int i = 0; i < edges; i++)
	{
		int n1, n2, weight;
		cin >> n1 >> n2 >> weight;

		AdjList[n1].push_back(make_pair(n2, weight));
		AdjList[n2].push_back(make_pair(n1, weight)); // undirected graph
	}

	cin >> s >> d; // scan source and destination vertex

	int ans = dijkstra(s, d, nodes);
	if (ans == -1)
		puts("No Path Exists");
	else
		cout << ans << endl;

	return 0;
}
