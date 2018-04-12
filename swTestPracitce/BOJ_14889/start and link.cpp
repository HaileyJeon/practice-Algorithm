#include<iostream>
#include<cmath>
using namespace std;
int N;
int ans; int num; int res;
int start; int link;
int input[20][20];
int d[20];

void solve(int cur, int cnt) {
	if (cnt == num) {
		int x1 = 0; int x2 = 0; start = 0; link = 0; 
		for (int i = 0; i < N-1; i++) {
			if (d[i] == 1) {
				 x1 = i;
			}
			else
				continue;
			for (int j = i + 1; j < N; j++) {
				if (d[j] == 1) {
					x2 = j;
				}
				else
					continue;

				start = start + input[x1][x2] + input[x2][x1];
			}
		}

		for (int i = 0; i < N - 1; i++) {
			if (d[i] == 0) {
				x1 = i;
			}
			else
				continue;
			for (int j = i + 1; j < N; j++) {
				if (d[j] == 0) {
					x2 = j;
				}
				else
					continue;

				link = link + input[x1][x2] + input[x2][x1];
			}
		}
		res = abs(start - link);

		if (res < ans)
			ans = res;
		return;
	}

	if (cur >= N)
		return;
	
	d[cur] = 1;
	solve(cur + 1, cnt + 1);
	d[cur] = 0;
	solve(cur + 1, cnt);
}

int main(void) {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input[i][j];
		}
	}

	ans = 100;
	num = N / 2;
	solve(0, 0);

	cout << ans << '\n';

	return 0;
}
