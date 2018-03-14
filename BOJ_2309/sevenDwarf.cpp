#include<iostream>
#include<algorithm>
using namespace std;
int input[9];
int total;

void solve() {
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			int out = input[i] + input[j];
			if ((total - out) == 100) {
				input[i] = 100;
				input[j] = 100;
				return;
			}
		}
	}
}

int main(void) {
	for (int i = 0; i < 9; i++) {
		cin >> input[i];
		total += input[i];
	}
	
	solve();
	sort(input, input + 9);

	for (int i = 0; i < 7; i++)
		cout << input[i] << endl;

	return 0;
}