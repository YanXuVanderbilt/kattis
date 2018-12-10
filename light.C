#include <iostream>
#include <vector>
using namespace std;
int p,q,s;


int main() {
	cin >> p >> q >> s;
	int num_p = s / p;
	vector<int> num_pv;
	for (int i = 1; i <= num_p; ++i) {
		num_pv.push_back(i*p);
	}
	int num_q = s/q;
	for (int j = 1; j <= num_q; ++j) {
		for (int i = 0; i < num_p; ++i) {
			if (j*q == num_pv[i]) {
				cout << "yes" << endl;
				return 0;
			}
		}
	}
	cout << "no" << endl;
	return 0;
}
	

