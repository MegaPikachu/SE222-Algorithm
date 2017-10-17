#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings) {
		int size = ratings.size();
		int count = 0;
		vector<int> numofcan;
		for (int i = 0; i < size; i++) {
			numofcan.push_back(1);
		}
		for (int i = 0; i < size - 1; i++) {
			if (ratings[i] < ratings[i + 1]) {
				numofcan[i + 1] = numofcan[i] + 1;
			}
		}

		for (int i = size - 1; i > 0; i--) {
			if (ratings[i - 1] > ratings[i]) {
				numofcan[i - 1] = numofcan[i] + 1;
			}
		}
		for (int i = 0; i < size; i++) {
			count += numofcan[i];
		}
		return count;
	}
};

int main() {
	Solution solution;
	vector<int> a;
	a.push_back(4);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(1);
	solution.candy(a);
	cin.get();
	return 0;
}