/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int> start, end;
        for (auto x : intervals) {
            start.push_back(x.start);
            end.push_back(x.end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int cnt=0,ans=0;
        int i=0,j=0;
        while (i < n) {
            if (start[i] < end[j]) {
                cnt++;
                ans = max(ans, cnt);
                i++;
            }
            else {
                cnt--;
                j++;
            }
        }

        return ans;
    }
};
