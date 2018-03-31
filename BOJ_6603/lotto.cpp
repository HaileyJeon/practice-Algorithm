#include<iostream>
using namespace std;
int S[13];
int ans[6];
int N;
void solve(int cnt, int cur) {
	if (cnt == 6) {
		for (int i = 0; i < 5; i++)
			cout << ans[i] << " ";
		cout << ans[5] << endl;
		return;
	}
	if (cur >= N)
		return;

	ans[cnt] = S[cur];
	solve(cnt+1, cur+1);
	solve(cnt, cur+1);
}
int main(void) {

	while (1) {
		cin >> N;
		if (N == 0)
			break;

		for (int i = 0; i < N; i++)
			cin >> S[i];

		solve(0, 0);
		cout << endl;
	}

	return 0;
}