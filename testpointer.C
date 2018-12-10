#include <iostream>
#include <vector>
using namespace std;

void testf(vector<int>* a) {
	cout << (*a)[1] << endl;
}

int main()
{
	vector<int> test;
	for (int i = 0; i < 10; ++i) {
		test.push_back(i+1);
	}
	vector<int> *t = &test;
	cout << (*t)[1] << endl;

	testf(t);
}
