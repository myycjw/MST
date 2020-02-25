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
const int N = 1e4 + 10;
int mp[N][N], point[N], ans;
bool vis[N];
bool prim() {
	memset(vis, 0, sizeof vis);
	memset(point, inf, sizeof point);
	point[1] = 0;
	for (int i = 1; i < n; i++) {
		int x = 0;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && (x == 0 || point[j] < point[x]))x = j;
		}
		vis[x] = 1;
		for (int y = 1; y <= n; y++) {
			if (!vis[y])point[y] = min(point[y], mp[x][y]);
		}
	}
	ans = 0;
	for (int i = 2; i <= n; i++) {
		if (point[i] == inf)
			return 0;
		ans += point[i];
	}
	return 1;
}
int main() {
	cin >> n >> m;
	int a, b, c;
	memset(mp, inf, sizeof mp);
	for (i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		mp[a][b] = mp[b][a] = c;
	}
	if (prim())
		cout << ans << endl;
	else
		cout << "can not get MST" << endl;
	return 0;
}
