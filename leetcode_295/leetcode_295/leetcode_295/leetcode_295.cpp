#include <iostream>  
#include <queue>
using namespace std;

class MedianFinder {
public:
	struct cmp {
		bool operator()(int &a, int &b) {
			return a > b;
		}
	};
	// Adds a number into the data structure.
	void addNum(int num) {
		if (left_size != 0) {
			if (num <= left.top()) {
				left.push(num);
				left_size++;
			}
			else {
				right.push(num);
				right_size++;
			}
		}
		else
		{
			if (right_size == 0) {
				left.push(num);
				left_size++;
			}
			else {
				if (num >= right.top()) {
					right.push(num);
					right_size++;
				}
				else {
					left.push(num);
					left_size++;
				}
			}

		}
		if (left_size <= (right_size - 2)) {
			left.push(right.top());
			right.pop();
			left_size++;
			right_size--;
		}
		else if (left_size >= (right_size + 2)) {
			right.push(left.top());
			left.pop();
			left_size--;
			right_size++;
		}
	}

	// Returns the median of current data stream
	double findMedian() {
		if (left_size == right_size) {
			int a = left.top();
			int b = right.top();
			return (left.top() + right.top()) / 2;
		}
		else if (left_size < right_size) {
			return right.top();
		}
		else {
			return left.top();
		}
	}
private:
	priority_queue<int> left;
	priority_queue<int, vector<int>, cmp > right;
	int left_size = 0;
	int right_size = 0;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

int main() {
	MedianFinder mf;
	mf.addNum(2);
	mf.findMedian();
	mf.addNum(3);
	mf.findMedian();
	mf.addNum(2);
	mf.findMedian();
	mf.addNum(6);
	mf.findMedian();
	mf.addNum(5);
	mf.findMedian();
	mf.addNum(0);
	mf.findMedian();
	mf.addNum(6);
	mf.findMedian();
	mf.addNum(3);
	mf.findMedian();
	mf.addNum(1);
	mf.findMedian();
	mf.addNum(0);
	mf.findMedian();
	mf.addNum(0);
	mf.findMedian();

	return 0;
}


/*
#include <iostream>
#include <vector>
using namespace std;


class MedianFinder {
public:

// Adds a number into the data structure.
void addNum(int num) {
int index = find_index(num, numbers);
insert(num, index, numbers);
}

void insert(int num, int index, vector<int>& numbers) {
int size = numbers.size();
if (index != size) {
numbers.push_back(num);
for (int i = size; i > index; i--) { //move the numbers to the right
numbers[i] = numbers[i - 1];
}
numbers[index] = num;  // insert num to the index
}
else {
numbers.push_back(num);
}
}

int find_index(int num, vector<int> numbers) {  // find the index to insert num and keep the vector sorted
int low;
int high;
int size = numbers.size();
if ( size == 0 || num <= numbers[0]  ) {
return 0;
}
else if (num >= numbers[size - 1]) {
return size;
}
else {

low = 0;
high = size - 1;

int middle;
int index;
while (low < high) { //quit when (low == high) or having found
middle = (low + high) / 2;
if (num > numbers[middle]) {
low = middle + 1;
}
else if (num < numbers[middle]) {
high = middle - 1;
}
else {
index = middle;
return index;
}
}
if (num <= numbers[low]) {
index = low;
}
else if (num > numbers[low]) {
index = low + 1;
}
return index;

}


}

// Returns the median of current data stream
double findMedian() {
int size = numbers.size();
if (size % 2 == 0) {
return 0.5*numbers[size / 2 - 1] + 0.5*numbers[size / 2];
}
else {
return numbers[size / 2];
}
}
private:
vector<int> numbers;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
*/