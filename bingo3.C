#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<vector<int>> numbers; 
//vector<int> initializer;
int n;
int num;
vector<int> input;
vector<int> commons;
vector<vector<int>> ties;
int tie = 0;
//vector<vector<int>> common_s;
//initializer.push_back(0); initializer.push_back(0);
void common() {
	for (int i = 0; i < num; ++i) {
		if (numbers[input[i]-1][1] == 1) {
			commons.push_back(input[i]);
		}
		else {
			numbers[input[i]-1][1] = 1;
		}
	}
}

int check_same(int a1, int a2, int a3, int a4, int a5, int b1, int b2, int b3, int b4, int b5) {
	// tested
	//
	vector<int> a,b;
	a.push_back(a1); a.push_back(a2); a.push_back(a3); a.push_back(a4); a.push_back(a5);
	b.push_back(b1); b.push_back(b2); b.push_back(b3); b.push_back(b4); b.push_back(b5);
	for (int i = 0; i < 5; ++i) {
		int same = 0;
		for (int j = 0; j < 5; ++j) {
			if (a[i] == b[j]) {
				same = 1;
			}
		}
		if (same == 0) {
			return 0;
		}
	}
	return 1;
}

int bingo(int c1, int c2, int a1, int a2, int a3, int a4, int a5) {
	// assume c1, c2 card numbers (larger than 0)
	for (int i = 0; i < num/5 + 1; ++i) {
		if (i/5 + 1 != c1 && i/5 + 1 != c2) {
			int check = i*5;
			if (check_same(input[check], input[check+1],input[check+2],input[check+3],input[check+4],a1,a2,a3,a4,a5) == 0) {} else {
				return 1;
			}
		}
	}
	return 0;
}
			


void find_common_set(int key) {
	vector<int> common_index;
	int card;
	for (int i = 0; i < num; ++i) {
		if (input[i] == key) {
			common_index.push_back(i);
		}
	}
	int s = common_index.size();
	for (int i = 0; i < s; ++i) {
                        vector<int> row;
			int start = common_index[i] - common_index[i] % 5;
			for (int k = start; k < start + 5; ++k) {
				row.push_back(input[k]);
			}
		for (int j = i + 1; j < s; ++j) {
			if (bingo(common_index[i]/25 + 1, common_index[j]/25 + 1, row[0],row[1],row[2],row[3],row[4]) == 0) {
			} else {
				tie = 1;
				vector<int> add;
				add.push_back(common_index[i]/25 + 1); add.push_back(common_index[j]/25 + 1);
				ties.push_back(add);
			}

		}
	}
}

void all_commons() {
	int size_commons = commons.size();
	for (int i = 0; i < size_commons; ++i) {
		find_common_set(commons[i]);
	}
}


			


void smallest_tie() {
	int tie_size = ties.size();
	int s1 = 10000; int s2 = 10000;
	for (int i = 0; i < tie_size; ++i) {
		if (ties[i][0] < s1 && ties[i][1] < s2) {
			s1 = ties[i][0]; s2 = ties[i][1];
		}
	}
	cout << s1 << " " << s2 << endl;
}




int main() {
	//cout << check_same(1,2,3,4,5,5,4,3,2,1) << endl;
	int common_size = commons.size();
	for (int i = 0; i < common_size; ++i) {
		cout << commons[i] << " ";
	}
	cout << endl;




	for (int i = 0; i < 3000; ++i) {
		vector<int> add;
		add.push_back(i+1); add.push_back(0);
		numbers.push_back(add);
	}
	
	scanf("%d",&n);
	num = 25 * n;
	for (int i = 0; i < num; ++i) {
		int in;
		scanf("%d",&in);
		input.push_back(in);
	}

	common();
	all_commons;
	if (tie == 0) {
		cout << "no ties" << endl;
	} else {
		smallest_tie();
	}	
}







