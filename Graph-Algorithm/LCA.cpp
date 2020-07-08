#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int nodes, edges;
map<int, vector<int> > graph;
int depth[N + 10];
int sparse_table[N + 10][22];
void take_data() {
	cin >> nodes >> edges;
	for (int i = 0; i < edges; i++) {
		int x, y;
		cin >> x >> y;
		// cout << x << " " << y << endl;
		graph[x].push_back(y);
		graph[y].push_back(x);

	}
}
int par[N + 10];
void dfs(int root = 1, int parent = 1, int dep = 0) {
	sparse_table[root][0] = parent;
	par[root] = parent;
	depth[root] = dep;
	for (auto x : graph[root]) {
		if (x == parent) continue;
		dfs(x, root, dep + 1);
	}
}
void build_table() {
	int mx = log2(nodes);
	for (int k = 1; k <= mx; k++) {
		for (int i = 1; i <= nodes; i++) {
			if (sparse_table[i][k] != -1) continue;
			int parent = sparse_table[i][k - 1];
			sparse_table[i][k] = sparse_table[parent][k - 1];
		}
	}

}

int lcs(int a, int b) {
	if (depth[a] > depth[b]) swap(a, b);
	int difference = depth[b] - depth[a];

	while (difference > 0) {
		int i = log2(difference);
		b = sparse_table[b][i];
		int x = 1 << i;
		difference -= x;
	}
	if (a == b) return a;
	int mx = log2(nodes);
	for (int i = mx; i >= 0; i--) {
		if (sparse_table[a][i] != -1 && (sparse_table[a][i] != sparse_table[b][i])) {
			a = sparse_table[a][i], b = sparse_table[b][i];
		}
	}

	return par[a];

}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	memset(depth, 0, sizeof(depth));
	take_data();
	memset(sparse_table, -1, sizeof(sparse_table));

	dfs();
	build_table();
	cout << lcs(1, 16);
}
