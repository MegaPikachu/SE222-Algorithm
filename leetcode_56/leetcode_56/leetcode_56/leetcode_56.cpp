#include <iostream>
#include <algorithm>
#include <vector>
#include<time.h>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(const Interval &Interval_1, const Interval &Interval_2) {
	if (Interval_1.start < Interval_2.start) {
		return true;
	}
	else {
		return false;
	}
}

class Solution {
public:


	vector<Interval> merge(vector<Interval>& intervals) {
		sort(intervals.begin(), intervals.end(), cmp);
		vector<Interval> result;
		int size = intervals.size();
		if (size > 0) {
			int last_start = intervals[0].start;
			int max_end = intervals[0].end;
			for (int i = 1; i < size; i++) {
				int start = intervals[i].start;
				int end = intervals[i].end;
				if (start == last_start) {
					if (end > max_end) {
						max_end = end;
					}
				}
				else if (start > last_start) {
					if (start <= max_end) {
						if (end > max_end) {
							max_end = end;
						}
					}
					else {
						Interval add(last_start, max_end);
						result.push_back(add);
						last_start = start;
						max_end = end;
					}

				}

				if (i == size - 1) {
					Interval last_add(last_start, max_end);
					result.push_back(last_add);
				}

			}



		}
		if (size == 1) {
			Interval last_add(intervals[0].start, intervals[0].end);
			result.push_back(last_add);
		}

		return intervals;

	}


};

int main() {
	/*
	
	Interval a(3, 4);
	Interval b(6, 4);
	Interval c(5, 2);
	Interval d(1, 2);
	Interval e(8, 7);

	vector<Interval> intervals;
	intervals.push_back(a);
	intervals.push_back(b);
	intervals.push_back(c);
	intervals.push_back(d);
	intervals.push_back(e);
	*/
	

	

	vector<Interval> intervals;
	srand(time(0));
	for (int i = 0; i < 50; i++) {
		Interval a(rand() % 100, rand() % 100);
		intervals.push_back(a);
	}
	Solution solution;
	solution.merge(intervals);

	/**/


	sort(intervals.begin(), intervals.end(), cmp);

	int size = intervals.size();
	for (int i = 0; i < size; i++) {
		cout << intervals[i].start << "->" << intervals[i].end << endl;
	}
	cin.get();
	return 0;
}

