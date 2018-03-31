#include<iostream>
using namespace std;
int in[4];
int out[4];

int main(void) {

	for (int i = 0; i < 4; i++) 
		cin >> out[i] >> in[i];
	
	int ans = in[0];
	int res = in[0];

	for (int i = 1; i < 4; i++) {
		res = res - out[i] + in[i];
		if (ans < res)
			ans = res;
	}
	cout << ans << endl;

	return 0;
}