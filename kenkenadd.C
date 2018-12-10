#include <iostream>
#include <vector>
using namespace std;
int size; int num_slots;int target;
vector<int> slots;
int sum(vector<int> ints) {
	int length = ints.size();
	int sum = 0;
	for (int i = 0; i < length;++i) {
		sum += ints[i];
	}
	return sum;
}

void slot_planner() {
	for (int i = 0; i < num_slots; ++i) {
		slots.push_back(1);
	}
	int remaining = sum(slots) - target;
	for (int i = num_slots-1;i>=0;--i) {
		if (size - 1 <= remaining) {
			slots[i] = size;
			remaining-=size-1;
		}
		if (remaining == 0) {
			break;
		}
	}
}

void printer(vector<int> ints) {
	int length = ints.size();
	for (int i = 0; i < length; ++i) {
		cout << ints[i] << " ";
	}
}

int main() {
	size = 9; target = 40; num_slots = 7;
	slot_planner();
	printer(slots);
}
