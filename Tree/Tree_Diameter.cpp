#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define MAX_N 100000
typedef vector<int> Vec;
typedef pair<int, int> pii;
 
struct Edge {
    int to, cost;
    Edge(int to, int cost) :
	to(to), cost(cost) {}
};
 
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
 
int N;
Graph G;
bool leaf[MAX_N];
 
Vec dijkstra(int s)
{
    Vec dist(N, INF);
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    Q.push(pii(0, s));
    while (!Q.empty()) {
	pii p = Q.top(); Q.pop();
	int v = p.second;
	if (dist[v] < p.first) {
	    continue;
	}
	for (int i = 0; i < (int)G[v].size(); i++) {
	    Edge &e = G[v][i];
	    if (dist[v] + e.cost < dist[e.to]) {
		dist[e.to] = dist[v] + e.cost;
		Q.push(pii(dist[e.to], e.to));
	    }
	}
    }
    return dist;
}
 
int get_farthest_point(int v)
{
    Vec vec = dijkstra(v);
    int resv = -1, max = -1;
    for (int i = 0; i < N; i++) {
	if (max < vec[i] && vec[i] != INF) {
	    max = vec[i];
	    resv = i;
	}
    }
    return resv;
}
 
int get_tree_diameter()
{
    int v = -1;
    for (int i = 0; i < N; i++) {
	if (!leaf[i]) {
	    v = i;
	    break;
	}
    }
    int v1 = get_farthest_point(v);
    int v2 = get_farthest_point(v1);
    Vec d = dijkstra(v2);
    int res = 0;
    for (int i = 0; i < (int)d.size(); i++) {
	if(d[i] != INF){
	    res = max(res, d[i]);
	}
    }
    return res;
}
 
void init()
{
    for (int i = 0; i < (int)G.size(); i++) {
	G[i].clear();
    }
    G.clear();
    G.resize(N);
    memset(leaf, 0, sizeof(leaf));
}
 
int main()
{
    int a, b, c;
    cin >> N;
    init();
    for (int i = 0; i < N-1; i++) {
        cin >> a >> b;
        a--; b--;
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, c);
    }
    cout << get_tree_diameter() << endl;
    return 0;
}
