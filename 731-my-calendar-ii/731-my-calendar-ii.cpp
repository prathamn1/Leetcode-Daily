// do brute force , if two interval are intersecting then put them in already_common with the specefied common portion now when a new interval comes and if it has something in common with any of interval in already_common which means some part is coming in three intervals means we have to return false.
// proceeding forward if any of our calendar interval is intersecting with the new inerval then trim it as above and put that common portion in already_common.


class MyCalendarTwo {
public:
    vector<pair<int,int>>calendar;
    vector<pair<int,int>>already_common;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        pair<int,int>p={start,end};
        for(auto [i,j]:already_common) {
            if(start<j and end>i) {
                return false;
            }
        }
        for(auto [i,j]:calendar) {
            if (start<j and end>i) {
                already_common.push_back(make_pair(max(start,i),min(end,j)));
            }
        }
        calendar.push_back(p);
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */