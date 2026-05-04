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
        if(intervals.empty()){
            return 0;
        }
        priority_queue<int, vector<int>, greater<int>> start{};
        priority_queue<int, vector<int>, greater<int>> end{};
        //sort(intervals.begin(), intervals.end(), [](const auto & a, const auto & b){return a.start < b.start;});
        int rooms = 1;
        int count = 0;
        for(const auto & i: intervals){
            start.push(i.start);
            end.push(i.end);
        }
        while(!start.empty() && !end.empty()){
            if(start.top() < end.top()){
                count++;
                start.pop();
            }
            else{
                count--;
                end.pop();
            }
            cout<< count<< endl;
            rooms = max(count, rooms);
        }
        return rooms;
    }
};
