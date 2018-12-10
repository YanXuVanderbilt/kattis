#include <iostream>
#include <vector>
using namespace std;
int a = 2;
void inc() {
	a+=1;
}
int main()
{
	inc();
	cout << a << endl;
	return 0;
}
