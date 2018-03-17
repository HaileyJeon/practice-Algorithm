#include<iostream>
using namespace std;

int N;
int power[10] = { 1,10,100,1000,10000,100000,1000000,10000000,100000000 };

bool Prime(int n) {
	if (n < 2)
		return false;
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0)
			return false;
	}
	return true;
}

bool solve(int num) {
	int res = 0;
	for (int i = N - 1; i >= 0; i--) {
		res = num / power[i];
		if (Prime(res) == false)
			return false;
	}
	return true;
}

int main(void) {

	cin >> N;

	for (int i = power[N - 1] + 1; i < power[N]; i++) {
		if (i == 1)
			continue;

		if (solve(i) == true)
			cout << i << endl;
	}
	return 0;
}