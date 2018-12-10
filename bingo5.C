//find set S of all numbers that appear on more than one card
//for each s in S
//-find all pairs of card c1,c2 that both contain s
//-for each pair, construct list L of numbers that appear in the same row as s in either c1 or c2
//-for all c card other than c1, c2, determine if L\{s} results in a bingo on card c;
//-if no card results in a bingo, then c1, c2 is a tie
//of all pairs of card that generate a tie, report the pair that is the smallest lexicographically
//if no pair is a tie, report this


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
vector<int> L; // assume no repetitive numbers
int tie = 0;
//vector<vector<int>> common_s;
//initializer.push_back(0); initializer.push_back(0);
void common() {
	//find out repeated numbers, add the numbers to the vector "commons"

	//tested
	//
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

int check_bingo(int a1, int a2, int a3, int a4, int a5, int key) {
	int b;
	vector<int> a;
	a.push_back(a1); a.push_back(a2); a.push_back(a3); a.push_back(a4);a.push_back(a5);
	int L_size = L.size();
	int key_index;
	for (int i = 0; i < L_size; ++i) {
		if (L[i] == key) {
			key_index = i;
			break;
		}
	}

	cout << "index of key is: " << key_index << endl;
/**
	for (int i = 0; i < L_size; ++i) {
		if (i != key_index) {
		b = 0;
		for (int j = 0; j < 5; ++j) {
			cout << L[i] << " " << a[j] << endl;
			if (L[i] == a[j]) {
				b = 1;
			}
		}
		if (b == 0) {
			return 0;
		}
		}
		cout << "this loop ended" << endl;
	}
	return 1;
**/
	for (int j = 0; j < 5; ++j) {
		b = 0;
		for (int i = 0; i < L_size; ++i) {
			if ( i != key_index) {
				cout << L[i] << " " << a[j] << endl;
				if (L[i] == a[j]) {
					b = 1;
				}
			}
		}
		if (b == 0) {
			return 0;
		}
		cout << "this loop ended" << endl;
	}
	return 1;
}

int bingo(int c1, int c2, int key) {
	// assume c1, c2 card numbers (larger than 0)
	//cout << "c1,c2,a1,a2,a4,a4,a5" << c1 << " " << c2 << " " << a1 << " " << a2 << " " << a3 << " " << a4 << " " << a5 << endl;
	for (int i = 0; i < num/5 + 1; ++i) {
		if (i/5 + 1 != c1 && i/5 + 1 != c2) {
			int check = i*5;
			if (check_bingo(input[check],input[check+1],input[check+2],input[check+3],input[check+4], key) == 0) {} else {
				return 1;
			}
		}
	}
	return 0;
}

void find_common_set(int key) {
	vector<int> a;
	L = a;
	vector<int> common_index;
	int card;
	for (int i = 0; i < num; ++i) {
		if (input[i] == key) {
			common_index.push_back(i);
		}
	}
	int s = common_index.size();
	for (int i = 0; i < s; ++i) {
		        for (int j = i + 1; j < s; ++j) {
				int start = common_index[i] - common_index[i] % 5;
				for (int k = start; k < start + 5; ++k) {
					L.push_back(input[k]);
				}
				int r_size = 5;
				start = common_index[j] - common_index[j]%5;
				for (int k = start; j < start + 5; ++k) {
					int same = 0;
					for (int v = 0 ; v < r_size; ++v) {
						if (L[v] == input[k]) {
							same = 1;
						}
					}
					if (same == 0) {
						L.push_back(input[k]);
					}
				}


				if (bingo(common_index[i]/25 + 1, common_index[j]/25 + 1, input[common_index[i]]) == 1) {
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
	L.push_back(1); L.push_back(2); L.push_back(3); L.push_back(4); L.push_back(5); L.push_back(6); L.push_back(7); L.push_back(8);
	cout << check_bingo(1,2,3,4,5,8) << endl;


	//cout << check_same(1,2,3,4,5,5,4,3,2,1) << endl;	


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

//int common_size = commons.size();
//	for (int i = 0; i < common_size; ++i) {
//		cout << commons[i] << " ";
//	}
//	cout << endl;




	all_commons();
	if (tie == 0) {
		cout << "no ties" << endl;
	} else {
		smallest_tie();
	}	
}









