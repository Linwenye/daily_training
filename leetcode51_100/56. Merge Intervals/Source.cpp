#include <vector>
#include <algorithm>
using namespace std;

/*
	Input: [[1, 3], [2, 6], [8, 10], [15, 18]]
	Output : [[1, 6], [8, 10], [15, 18]]
*/

struct Interval
{
	int start;
	int end;
	Interval() :start(0), end(0) {}
	Interval(int s, int e) :start(s), end(e) {}
};

int cmp(const Interval &a, const Interval& b) {
	return a.start < b.start;
}
class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> res;
		if (intervals.empty())
		{
			return res;
		}
		sort(intervals.begin(), intervals.end(), cmp);
		res.push_back(intervals[0]);
		for (Interval & interval : intervals)
		{
			if (interval.start<=res.back().end)
			{
				res.back().end = max(res.back().end, interval.end);
			}
			else {
				res.push_back(interval);
			}
		}
		return res;
	}
};

int main() {
	Interval a(1, 3);
	Interval b(2, 4);
	vector<Interval> t;
	t.push_back(a);
	t.push_back(b);
	Solution so;
	so.merge(t);

}