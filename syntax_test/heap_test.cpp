#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/*
   scanf and printf more efficient than cin and cout

   using heap to dynamically get the mid num
*/

void print_vec(vector<int> vec);
int main() {
	int num = 0;
	vector<int> vec;
	while (scanf("%d", &num) != EOF) {
		vec.push_back(num);
		push_heap(vec.begin(), vec.end());
	}
	print_vec(vec);
	pop_heap(vec.begin(), vec.end());
	print_vec(vec);

	return 0;
}

void print_vec(vector<int> vec) {
	for (int i : vec) {
		printf("%d ",i);
		printf("\n");
	}
}