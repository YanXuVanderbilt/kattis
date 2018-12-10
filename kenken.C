#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <tuple>
using namespace std;
int size;//largest legal number; in 8x8, it would be 8
int num_grids;
long long target;
char op;
class point {
	public:
		int row,col;
		long long value;
		int in_row,in_col;
};
vector<point> points;//containing locations of the squares

void op_minus() {
	//tested
	
	long long result = 2*(size - target);
	cout << result << endl;
}

void op_division() {
	long long count;
	for (int i = 1; i < size; ++i) {
		for (int j = i + 1; j <= size; ++j) {
			if (target*i == j) {
			       ++count;
			}
		}
	}
	cout << 2*count << endl;
}

vector<vector<point>> lines;
vector<vector<int>> grid;

void grid_planner() {
	int num_points = points.size();
	for (int i = 1; i <= size; ++i) {
		vector<point> line1,line2;
		for (int j = 0; j < num_points; ++j) {
			if (points[j].row == i) {
				//check row
				line1.push_back(points[j]);
			}
			if (points[j].col == i) {
				line2.push_back(points[j]);
			}
		}
		lines.push_back(line1);lines.push_back(line2);
	}

}

int check_line(vector<point> line) {
	//tested
	//0 means pass, 1 means fail
	vector<int> numbers;
	int num = line.size();
	for (int i = 1; i <= size; ++i) {
		numbers.push_back(i);
	}
	for (int i = 0; i < num; ++i) {
		int v = line[i].value;
		if (numbers[v-1] != -1) {
			numbers[v-1] = -1;
		}
		else {
			// test code 
			cout << "1" << endl;

			return 1;
		}
	}
	//test code
	cout << "0" << endl;

	return 0;
}	

void op_add() {}

void driver() {
	cin >> size >> num_grids >> target >> op;
	for (int i = 0; i < num_grids; ++i) {
		int r,c;
		cin >> r >> c;
		point temp;
		temp.row = r; temp.col = c;
		points.push_back(temp);
	}
	op_minus();

//testcode
//vector<point> test_pass;
//vector<point> test_fail;
//point point1; point1.value = 2;
//point point2; point2.value = 3;
//point point3; point3.value = 3;
//test_pass.push_back(point1); test_pass.push_back(point2);
//test_fail.push_back(point2); test_fail.push_back(point3);
//check_line(test_pass); check_line(test_fail);


}

int main() {
	driver();
}


