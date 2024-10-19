class Solution {
public:

    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return true;
        sort(intervals.begin(), intervals.end());
        int endGlobal = intervals[0][1];
        for(int i = 1 ; i < intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(start < endGlobal) return false;
            endGlobal = max(endGlobal, end);

        }
        return true;
    }
};