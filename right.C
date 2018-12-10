#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n;
string indata;
vector<int> result;
void print() {
	int s = result.size();
	for (int i = 0; i < s; ++i) {
		//cout << result[i] << " ";
	}
	cout << endl;
}
int main() {
	cin >> n >> indata;
	int index = 1;
	int repeat = 0;
	//int d = 0;
	result.push_back(1);
	indata+='R';
	while (index < n + 1) {
		if (indata[index-1] == 'R') {
			if (repeat >0) {
				//cout << "index is" << index << endl;
				result[index-repeat-1]+=repeat;
			}
			int r = result[index-repeat-1];
			for (int i = 0; i < repeat;++i) {
				result.push_back(r-i-1);
			}
			repeat = 0;
			result.push_back(index+1);
			++index;
			//print();
		}
		if (indata[index-1] == 'L') {
			repeat+=1;
			++index;
			//print();
		}
	}
	for (int i = 0; i < n; ++i) {
		 printf("%d",result[i]);
		 printf("\n");
	}
}
		




