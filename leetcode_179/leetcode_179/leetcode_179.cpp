#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const string& num_1, const string& num_2) {
	string no_1 = num_1 + num_2;
	string no_2 = num_2 + num_1;
	if (no_1 > no_2) {
		return 1;
	}
	else {
		return 0;
	}
}



class Solution {
public:

	void int_to_string(vector<int> nums , vector<string>& output) {
		int size = nums.size();
		for (int i = 0; i < size; i++) {
			stringstream ss;
			ss << nums[i];
			output.push_back(ss.str());
		}
	}
	string largestNumber(vector<int>& nums) {
		vector<string> string_nums;
		int_to_string(nums, string_nums);
		sort(string_nums.begin(), string_nums.end(), cmp);
		string result;
		int size = string_nums.size();
		for (int i = 0; i < size; i++) {
			result += string_nums[i];
		}
		if (result[0] == '0') {
			return "0";
		}
		return result;
	}
};


int main() {
	vector<string> test;
	test.push_back("2");
	test.push_back("233");
	test.push_back("233");
	test.push_back("231");
	test.push_back("236");
	test.push_back("21211");
	test.push_back("29232");
	test.push_back("266");
	test.push_back("224");
	test.push_back("54");
	test.push_back("64");
	test.push_back("112");

	sort(test.begin(), test.end(), cmp);

	int size = test.size();
	for (int i = 0; i < size; i++) {
		cout << test[i] << "--";
	}

	cin.get();
	return 0;
}