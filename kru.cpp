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
int fa[N],ans;
int get(int x) {
	return fa[x] == x ? x : fa[x] = get(fa[x]);
}
void merge(int x, int y) {
	fa[get(x)] = get(y);
}
struct rec {
	int x, y, z;
	bool friend operator<(const rec& a, const rec& b) {
		return a.z < b.z;
	}
}e[M];
bool kruskal() {
	for (i = 1; i <= n; i++)
		fa[i] = i;
	sort(e + 1, e + 1 + m);
	ans = 0;
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		int fx = get(e[i].x), fy = get(e[i].y);
		if (fx == fy)
			continue;
		merge(fx, fy);
		cnt++;
		ans += e[i].z;
	}
	return cnt == n - 1;
}
int main() {
	cin >> n >> m;
	for (i = 1; i <= m; i++) {
		cin >> e[i].x >> e[i].y >> e[i].z;
	}
	if (kruskal())
		cout << ans << endl;
	else
		cout << "can not get MST" << endl;
	return 0;
}
