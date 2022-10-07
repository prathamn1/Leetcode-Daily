class MyCalendar {
public:
    vector<pair<int,int>>intervals;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        pair<int,int>p={start,end};
        int k=lower_bound(intervals.begin(),intervals.end(),p)-intervals.begin();
        cout<<k<<endl;
        bool found=true;
        if(k-1>=0) {
            if(start<intervals[k-1].second) {
                found=false;
            }
        }
        if(k<intervals.size()) {
            if(end>intervals[k].first) {
                found=false;
            }
        }
        if(found) {
            intervals.insert(intervals.begin()+k,p);
            return true;
        }
        return false;
    }
};




/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */