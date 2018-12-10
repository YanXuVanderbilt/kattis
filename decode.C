#include <iostream>
#include <vector>
#include <string>
using namespace std;
string indata;

string encode() {
	int length = indata.length();
	int repeat = 0;
	char now = indata[0];
	char z = '0';
	int index = 0;
	string result;
	while(index < length) {
		while (indata[index] == now) {
			repeat += 1;
			//cout << "repeat is" << repeat << endl;
			index += 1;
		}
		result += now;
		char add = z + repeat;
		//cout << "add is" << add << endl;
		result += add;
		now = indata[index];
		repeat = 0;
	}
	return result;
}

string decode() {
	string result;
	//char z = "0";
	int length = indata.length();
	//int looptime = length/2;
	int index = 0;
	char temp, repeat;
	int time;
	while (index < length) {
		temp = indata[index];
		//cout << "temp is " << temp << endl;
		++index;
		repeat = indata[index];
		//cout << "repeat is " << repeat << endl;
		time = repeat - '0';
		//cout << "time is " << time << endl;
		for (int i = 0; i < time; ++i) {
			result += temp;
		}
		++index;
	}
	return result;
}



int main() {
	char type;
	cin >> type >> indata;
	if (type == 'E') {
		cout << encode() << endl;
		return 0;
	}
	if (type == 'D') {
		cout << decode() << endl;
		return 0;
	}
}
		

		


