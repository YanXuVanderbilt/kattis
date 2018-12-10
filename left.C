#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> result;
vector<char> command;
char cmd;
string com;
int largest = 0;

int main() {
	result.push_back(1);
	string indata;
	scanf("%d",&n);
	cin >> com;
	int last_right = 0;

	for (int i = 0; i < n-1; ++i) {
		if (com[i] == 'R') {
			result.push_back(result.size() + 1);
			last_right = i+1;
		}
		if (com[i] == 'L') {
			int size = result.size();
			for (int j = last_right; j < size; ++j) {
				result[j]+=1;
			}
			result.push_back(result[size-1]-1);
			
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%d",result[i]);
		printf("\n");
	}
}

	


	
