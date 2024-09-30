class MyCalendar {
public:
    vector<pair<int, int>> bookings;
    MyCalendar() {
        
    }
    
    bool isDoubleBooking(int currentStart, int currentEnd, int bookingStart, int bookingEnd){
        if (bookingStart >= currentEnd || bookingEnd <= currentStart) return false;
        return true;
    }

    bool book(int start, int end) {
        int exsitedBookingNumber = bookings.size();
        for(int i = 0 ; i < exsitedBookingNumber; i++){
            int bookingStart = bookings[i].first;
            int bookingEnd = bookings[i].second;
            if(isDoubleBooking(bookingStart, bookingEnd, start , end)) return false;
        }
        bookings.push_back({start, end});
        return true;

    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */



// in random order

// big o of n square                
// 10 questions , type and fix the problems , fix the structure of the sentences
