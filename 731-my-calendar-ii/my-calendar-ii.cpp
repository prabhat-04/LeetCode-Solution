class MyCalendarTwo {
    int maxOverlappedBooking ;
    map<int,int> bookingCount;
public:
    MyCalendarTwo() {
        maxOverlappedBooking = 2;
    }
    
    bool book(int start, int end) {
        bookingCount[start]++;
        bookingCount[end]--;
        int overlappedBooking =0;
        for(auto &bookings:bookingCount){
            overlappedBooking+=bookings.second;
            if(overlappedBooking > maxOverlappedBooking){
                bookingCount[start]--;
                bookingCount[end]++;
                if(bookingCount[start]==0){
                    bookingCount.erase(start);
                }
                if(bookingCount[end]==0){
                    bookingCount.erase(end);
                }
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */