#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> indata;
int tempin;
vector<vector<int>> numbers;
int n;
int main() {
	scanf("%d",&n);
	int check;
	vector<int> add;
	add.push_back(0); add.push_back(0);
	for (int i = 0; i < 3001; ++i) {
		numbers.push_back(add);
	}
	for (int i = 0; i < 25*n; ++i) {
		scanf("%d",&tempin);
		indata.push_back(tempin);
	}
	for (int i = 0; i < n*25; ++i) {
		if (numbers[indata[i]-1][0] == 1) {
			printf("%d",numbers[indata[i]-1][1]/5+1);
			printf(" ");
			//cout << " " <<  i%25+1 << endl;
			printf("%d",i/25+1);
		printf("\n");
			return 0;
		} else {
			numbers[indata[i]-1][0] = 1;
			numbers[indata[i]-1][1] = i/5;;
		}
	}
	cout << "no ties" << endl;
	return 0;
}
	

