#include<iostream>
using namespace std;
int T[15];
int P[15];
int N;
int ans;

void solve1(int index, int price) {

	if (index >= N)
		return;

	if (index + T[index] <= N) {
		if (price+P[index] > ans)
			ans = price+P[index];
		solve1(index + T[index], price + P[index]);
	}
	solve1(index + 1, price);
}

void solve2(int day, int money) {

	if (day == N) {
		if (ans < money)
			ans = money;
		return;

	}
	if (day > N)
		return;

	solve2(day + T[day], money + P[day]);//����Ѵ�
	solve2(day + 1, money);//������� �ʴ´�
}

int main(void) {

	cin >> N;

	ans = 0;

	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}

	//solve1(0, 0); // �̷��� �ٶ󺸴� �������� Ǫ�¹��
	solve2(0, 0); // ����������� ó��

	cout << ans << '\n';
}