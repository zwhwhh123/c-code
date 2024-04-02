#include <bits/stdc++.h>
using namespace std;
const int N=660;
const int inf = 0x3f3f3f;
int m, n, start, end;
int global; 
int sec[N], e[N][N], dis[N], value[N];
bool book[N];
void init()
{
	int u, v, w;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(i==j)
				e[i][j] = 0;
			else e[i][j] = inf;	
	for(int i=0; i<n; i++)
		scanf("%d", &sec[i]);
	for(int i=1; i<=m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		e[u][v] = e[v][u] = w;
	}	
}
void Dijkstra()
{
	memset(book, false, sizeof(book));
	for(int i=0; i<n; i++) {
		dis[i] = e[start][i];
		value[i] = sec[i] + sec[start];
	}
	book[start] = true;
	value[start] = sec[start];
	for(int i=0; i<n; i++) {
		int mini = inf;
		int u = n;
		for(int j=0; j<n; j++) {
			if(dis[j] < mini && book[j] == false) {
				mini=dis[j];
				u=j;	
			}
		}
		if(u==n)
			break;
		book[u] = true;
		for(int v=0; v<n; v++) {
			if(u==v)
				continue;
			if(dis[v] > dis[u] + e[u][v]) {
				dis[v] = dis[u] + e[u][v];
				value[v] = value[u] + sec[v];
			}
			if(dis[v] == dis[u] + e[u][v])
				value[v] = max(value[u] + sec[v], value[v]);
		}
	}
}
int main()
{
	while(scanf("%d%d%d%d", &n, &m, &start, &end)!=EOF)
	{
		init();
		Dijkstra();
		for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << e[i][j] << " ";
		cout << endl;
	}
	for (int i = 0;i < n; i++)
		cout << dis[i] << " ";
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << value[i] << " ";
	cout << endl; 
	}	
	return 0; 
}
