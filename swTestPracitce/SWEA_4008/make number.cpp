#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector <int> v;
int N;
int op[4];
int num[12];
int ans;  int M; int m;

void solve(int index, int number) {

	if (index == N) {
		v.push_back(number);
		return;
	}

	if (index > N)
		return;

	if (op[0] != 0) {
		op[0]--; 
		solve(index + 1, number + num[index]);
		op[0]++;
	}
	if (op[1] != 0) {
		op[1]--;
		solve(index + 1, number - num[index]);
		op[1]++;
	}
	if (op[2] != 0) {
		op[2]--;
		solve(index + 1, number * num[index]);
		op[2]++;
	}
	if (op[3] != 0) {
		op[3]--;
		solve(index + 1, number / num[index]);
		op[3]++;
	}
}

int main(void) {
	int T;
	cin >> T;
	int t = 0;
	while (T--) {
		ans = 0; M = - 100000000; m = 100000000;

		cin >> N;
		for (int i = 0; i < 4; i++) 
			cin >> op[i];
		
		for (int i = 0; i < N; i++) 
			cin >> num[i];
		
		solve(1, num[0]);
		
		sort(v.begin(), v.end());
		ans = v[v.size() - 1] - v[0];

		t++;
		cout << "#" << t << " " << ans << endl;
	}
	return 0;
}