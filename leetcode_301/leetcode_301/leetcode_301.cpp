#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
using namespace std;

class Solution {
public:
	int who_has_more(string s) { // return 1 if left has more parentheses,if right has return 2,if equal return 0
		int size = s.size();
		int left = 0;
		int right = 0;
		for (int i = 0; i < size; i++) {
			if (s[i] == '(') {
				++left;
			}
			else if (s[i] == ')') {
				++right;
			}
		}
		if (left == right) {
			return 0;
		}
		else if (left > right) {
			return 1;
		}
		else {
			return 2;
		}
	}

	bool is_valid(string s) { // valid ----return true;else ----return false
		stack<char> left;
		int size = s.size();
		if (size == 0) {
			return true;
		}
		if (s[0] == ')') {
			return false;
		}
		if (s[0] == '(') {
			left.push(s[0]);
		}
		for (int i = 1; i < size; i++) {
			if (s[i] == '(') {
				left.push(s[i]);
			}
			else if (s[i] == ')') {
				if (!left.empty()) {
					left.pop();
				}
				else {
					return false;
				}
			}
		}
		if (left.empty()) {
			return true;
		}
		else {
			return false;
		}
	}

	vector<string> removeInvalidParentheses(string s) {
		char par[3];
		int done = 0;
		set<string> delete_same;
		par[1] = '(';
		par[2] = ')';
		queue<string> all_possible;
		queue<string> next_possible;
		vector<string> result;
		vector<string> temp;
		all_possible.push(s);

		while (!all_possible.empty()) {
			string test = all_possible.front();
			all_possible.pop();
			if (is_valid(test)) {
				result.push_back(test);
				done = 1;
			}
			else if (done == 0 ){
				int left_or_right = who_has_more(test);
				if (left_or_right == 0 ) {
					int count_left = 0;
					int size = test.size();
					string res = "";
					for (int i = 0; i < size; i++) {
						if (test[i] == '(') {
							count_left++;
							res = res + '(';
						}
						else if (test[i] == ')') {
							if (count_left > 0) {
								count_left--;
								res = res + ')';
							}
						}
						else {
							res = res + test[i];
						}
					}
					int thesize = res.size();
					int index = 0;
					int i = 0;
					while (index < count_left) {
						if (res[thesize - 1 - i] == '(') {
							index++;
							if (i >= 1) {
								res = res.substr(0, thesize - 1 - i) + res.substr(thesize - i);
							}
							else if (i == 0) {
								res = res.substr(0, thesize - 1 - i);
							}

						}
						i++;
					}
					if (res != "") {
						if (delete_same.count(res) == 0) {
							temp.push_back(res);
							delete_same.insert(res);
						}
						
					}

				}
				else {
					char del_par = par[left_or_right];
					int size = test.size();
					for (int i = 0; i < size; i++) { // delete one char which is the extra parenthese
						if (test[i] == del_par) {
							string add = test.substr(0, i) + test.substr(i + 1);
							if (delete_same.count(add) == 0) {
								next_possible.push(add);
								delete_same.insert(add);
							}
						}
					}
				}

				if (all_possible.empty() && done == 0) {
					while (!next_possible.empty()) {
						all_possible.push(next_possible.front());
						next_possible.pop();
					}
				}

			}
		}

		if (result.empty()) {
			int size = temp.size();		
			for (int i = 0; i < size; i++) {
				result.push_back(temp[i]);
			}
		}
		if (result.empty()) {
			result.push_back("");
		}

//		if (result.empty()) {
//			int size = s.size();
//			string ins = "";
//			for (int i = 0; i < size; i++) {
//				if (s[i] != '(' && s[i] != ')') {
//					ins = ins + s[i];
//				}
//			}
//			result.push_back(ins);
//		}

//		int ssize = result.size();
//		for (int i = 0; i < size; i++) {
//			if (result[i] == "" && size > 1) {

	//		}
//		}


		return result;
	}
};

