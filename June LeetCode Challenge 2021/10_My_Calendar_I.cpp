class MyCalendar {
public:
    vector<pair<int,int>> interval;
    int prev;
    MyCalendar() {
        prev = -1;
    }
    
    bool book(int start, int end) {
        sort(interval.begin(), interval.end());
        for(auto p : interval){
            if(start < p.second && end > p.first)
                return false;
        }
        interval.push_back({start,end});
        return true;
    } 
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
