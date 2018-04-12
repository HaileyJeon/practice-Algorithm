#include<iostream>
using namespace std;
int price[4];
int input[12];
int ans;

void solve(int m, int p) {

	if (m == 12) {
		if (ans > p)
			ans = p;
 		return;
	}

	if (m > 12)
		return;
	
	solve(m + 3, p + price[2]);
	solve(m + 1, p + price[1]);
	solve(m + 1, p+input[m]);
	
}

int main(void) {
	int T;
	cin >> T;
	int t = 0;

	while (T--) {

		for (int i = 0; i < 4; i++)
			cin >> price[i];

		for (int i = 0; i < 12; i++) {
			cin >> input[i];
			if (input[i] != 0)
				input[i] *= price[0];
			//if (input[i] > price[1])
			//	input[i] = price[1];
		}

		ans = price[3];
		solve(0, 0);

		t++;
		cout << "#" << t << " " << ans << endl;
	}
	return 0;
}