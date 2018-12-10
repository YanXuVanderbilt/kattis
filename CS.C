#include <iostream>
using namespace std;
int main()
{
	int temp, total = 0;
	scanf("%d",&temp);
	while (scanf("%d",&temp) == 1) {
		if (temp < 0) {
			++total;
		}
	}
	printf("%d",total);
}
