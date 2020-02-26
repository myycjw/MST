#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <map>
using namespace std;
typedef int long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 1e3 + 10;
#define pi 3.141592653589794626
int i, j, k;
int m, n, q;
const int M = 1e5 + 10;
const int N = 1e5 + 10;
int fa[N], ans;
int f(int x) {
	return fa[x] == x ? x : fa[x] = f(fa[x]);
}
void find(int x, int y) {
	fa[f(x)] = f(y);
}
struct reo {
	int x, y, z;
	bool friend operator<(const reo& a, const reo& b) {
		return a.z < b.z;
	}
}edge[M];
bool kruskal() {
	for (i = 1; i <= n; i++)
		fa[i] = i;
	sort(edge + 1, edge + 1 + m);
	ans = 0;
	int cnt = 0;
	for (i = 1; i <= m; i++) {
		int fx = f(edge[i].x), fy = f(edge[i].y);
		if (fx == fy)
			continue;
		find(fx, fy);
		cnt++;
		ans += edge[i].z;
	}
	return cnt == n - 1;
}
int main() {
	cin >> n >> m;
	for (i = 1; i <= m; i++) {
		cin >> edge[i].x >> edge[i].y >> edge[i].z;
	}
	if (kruskal())
		cout << ans << endl;
	else
		cout << "can not get MST" << endl;
	return 0;
}
