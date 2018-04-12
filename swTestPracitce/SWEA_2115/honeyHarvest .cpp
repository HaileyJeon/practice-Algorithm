#include<iostream>
#include<algorithm>
using namespace std;
int N, M, C;
int res; int ans; int sp;
int map[10][10];
int MAP[10][10];
bool selected[10][10];

void init() {
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			map[i][j] = 0;
			MAP[i][j] = 0;
			selected[i][j] = false;
		}
	}
}

void sel(int x, int y, int honey, int honeyhoney) {

	if (y == sp + M && honey <= C) {
		if (res < honeyhoney)
			res = honeyhoney;
		return;
	}
	if (honey > C)
		return;

	sel(x, y + 1, honey + map[x][y], honeyhoney + MAP[x][y]);
	sel(x, y + 1, honey, honeyhoney);
}

int main(void) {
	int T;
	cin >> T;
	int t = 0;
	while (T--) {

		cin >> N >> M >> C;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				MAP[i][j] = pow(map[i][j], 2);
			}
		}

		ans = 0;
		for (int t = 0; t < 2; t++) {
			int temp = 0;
			int x = 0;
			int y = 0;

			for (int i = 0; i < N; i++) {
				for (int j = 0; j <= N - M; j++) {
					if (selected[i][j] == true || selected[i][j + M - 1] == true)
						continue;

					res = 0; sp = j;
					sel(i, j, 0, 0);

					if (res > temp) {
						temp = res;
						x = i;
						y = j;
					}
				}
			}

			ans += temp;

			for (int i = y; i < y + M; i++)
				selected[x][i] = true;
		}
		t++;
		cout << "#" << t << " " << ans << endl;

		init();
	}
	return 0;
}