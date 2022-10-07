class MyCalendarThree {
public:
    map<int,int>event;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        int max_common=0,current_common=0;
        event[start]++;
        event[end]--;
        for(auto [i,j] : event) {
            current_common+=j;
            max_common=max(max_common,current_common);
        }
        return max_common;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */