#include <vector>
#include <algorithm>
using namespace std;

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
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> res;
		if (intervals.empty())
		{
			res.push_back(newInterval);
			return res;
		}
		int i = 0;
		while (i < intervals.size() && intervals[i].start < newInterval.start)
		{
			res.push_back(intervals[i++]);
		}
		if ((!res.empty())&&newInterval.start <= res.back().end)
		{
			res.back().end = max(newInterval.end, res.back().end);
		}
		else {
			res.push_back(newInterval);
		}
		while (i < intervals.size()) {
			if (intervals[i].start <= res.back().end)
			{
				if (intervals[i].end >= res.back().end)
				{
					res.back().end = intervals[i].end;
					while (++i<intervals.size())
					{
						res.push_back(intervals[i]);
					}
					return res;
				}
			}
			else {
				while (i < intervals.size())
				{
					res.push_back(intervals[i++]);
				}
				return res;
			}
			i++;
		}
		return res;
	}
};