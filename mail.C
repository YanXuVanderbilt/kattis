#include <iostream>
#include <string>
#include <vector>
using namespace std;
long long n;
vector<int> houses;
vector<int> result;
int position;
void left() {
	cout << "left is called" << endl;
	position-=1;
	while (houses[position-1] == 1) {
		position-=1;
	}
	houses[position-1] = 1;
	//cout << position << endl;
	result.push_back(position);
}

void right() {
	cout << "right is called" << endl;
	position+=1;
	while (houses[position-1] == 1) {
		position+=1;
	}
	houses[position-1] = 1;
	//cout << position << endl;
	result.push_back(position);
}

int shift_print() {
	long long smallest = 2 * 100000 + 1;
	for (int i = 0; i < n; ++i) {
		if (result[i] < smallest) {
			smallest = result[i];
		}
	}
	long long shift = 1 - smallest;
	for (int i = 0; i < n; ++i) {
		result[i]+=shift;
		cout << result[i] << endl;
	}
}





int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		houses.push_back(0);
	}
	string command;
	cin >> command;
	if (command[0] == 'L') {
		position = 2;
		houses[position-1] = 1;
		result.push_back(position);
		//cout << position << endl;
	} else {
		position = 1;
		houses[position-1] = 1;
		result.push_back(position);
		//cout << position << endl;
	}
	for (int i = 0; i < n-1; ++i) {
		if (command[i] == 'L') {
			left();
		} else {
			right();
		}
	}
	shift_print();
}

