#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution {
public:
	struct Min_max {
		int min_i;
		int max_i;
	};

	struct Value_index {
		int value;
		int index;
		bool operator < (const Value_index &another) const {
			return value < another.value;
		}
	};
	int maxArea(vector<int>& height) {
		Value_index* value_indexes = new Value_index[height.size()];
		for (int i = 0; i < height.size(); i++)
		{
			value_indexes[i].index = i;
			value_indexes[i].value = height[i];
		}
		sort(value_indexes, value_indexes + height.size());

		// calculate min_max indexes
		Min_max* min_maxs = new Min_max[height.size()];
		min_maxs[height.size() - 1].min_i = min_maxs[height.size() - 1].max_i = value_indexes[height.size() - 1].index;
		for (int i=height.size()-2;i>=0;i--)
		{
			min_maxs[i].min_i = value_indexes[i].index < min_maxs[i + 1].min_i ? value_indexes[i].index:min_maxs[i+1].min_i;
			min_maxs[i].max_i = value_indexes[i].index > min_maxs[i + 1].max_i ? value_indexes[i].index:min_maxs[i+1].max_i;
		}

		// get result
		int result = 0;
		for (size_t i = 0; i < height.size(); i++)
		{
			// get the right point with longest distances with point_i
			int temp_area = value_indexes[i].value*
				max(abs(value_indexes[i].index - min_maxs[i].max_i), abs(value_indexes[i].index - min_maxs[i].min_i));
			result = temp_area > result ? temp_area : result;
		}

		return result;
	}
};

int main() {
	int a[] = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	vector<int> heights(a, a + 9);
	Solution so;
	cout<<so.maxArea(heights);
	return 0;
}