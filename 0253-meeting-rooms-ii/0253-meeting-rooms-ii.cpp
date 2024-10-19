class Solution {
public:

    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        minHeap.push(intervals[0][1]);
        int neededMeetingRoom = 1;

        for(int i = 1 ; i < intervals.size(); i++){
            int currentEndTime = intervals[i][1];
            int currentStartTime = intervals[i][0];
            int soonestEndTime = minHeap.top();
            
            if(soonestEndTime <= currentStartTime){
                minHeap.pop();
                minHeap.push(currentEndTime);
            }else{
                neededMeetingRoom += 1;
                cout<<currentStartTime<<"-"<<soonestEndTime<<endl;
                minHeap.push(currentEndTime);
            }
        }
        return neededMeetingRoom;
    }
};