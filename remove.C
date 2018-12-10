#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int> numbers;
	numbers.push_back(1); numbers.push_back(2); numbers.push_back(3);
	cout << numbers[1] << endl;
	numbers[1] = 4;
	//numbers.erase(numbers.begin() + 1);
	cout << numbers[1] << endl;
}
